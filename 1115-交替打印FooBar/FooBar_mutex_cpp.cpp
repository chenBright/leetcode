#include <functional>
#include <mutex>
using namespace std;

class FooBar {
private:
    int n;
    mutex mutex1_;
    mutex mutex2_;

public:
    FooBar(int n) {
        this->n = n;

        mutex2_.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            mutex1_.lock();

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            mutex2_.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            mutex2_.lock();
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            mutex1_.unlock();
        }
    }
};
