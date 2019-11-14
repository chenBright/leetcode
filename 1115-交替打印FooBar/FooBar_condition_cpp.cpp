#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;

class FooBar {
private:
    int n;
    mutex mutex_;
    condition_variable cond_;
    bool flag;

public:
    FooBar(int n) : flag(true) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
        unique_lock<mutex> lock(mutex_);
            while (flag != true) {
                cond_.wait(lock);
            }

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            flag = false;
            cond_.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
        unique_lock<mutex> lock(mutex_);
            while (flag != false) {
                cond_.wait(lock);
            }
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            flag = true;
            cond_.notify_all();
        }
    }
};
