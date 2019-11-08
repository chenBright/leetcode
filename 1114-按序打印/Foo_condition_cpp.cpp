#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;

class Foo {
public:
    Foo() :  flag1(false), flag2(false) {
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        flag1 = true;
        mutex_.unlock();
        cond_.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mutex_);
        // 直到 falg1 == true，才能进入临界区
        while (flag1 != true) {
            cond_.wait(lock);
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        flag2 = true;
        cond_.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mutex_);
        // 直到 falg1 == true && flag2 == true，才能进入临界区
        while (flag1 != true || flag2 != true) {
            cond_.wait(lock);
        }
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    mutex mutex_;
    condition_variable cond_;

    bool flag1;
    bool flag2;
};
