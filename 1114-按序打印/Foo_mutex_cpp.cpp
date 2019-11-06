#include <functional>
#include <mutex>
using namespace std;

class Foo {
public:
    Foo() {
        mutex1_.lock();
        mutex2_.lock();
    }


    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        // 解锁 mutex1_
        mutex1_.unlock();
    }

    void second(function<void()> printSecond) {
        // 对 mutex1_ 上锁
        mutex1_.lock();

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        // 解锁 mutex2_
        mutex2_.unlock();

        mutex1_.unlock();
    }

    void third(function<void()> printThird) {
        // 对 mutex2_ 上锁
        mutex2_.lock();
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();

        // 解锁 mutex2_
        mutex2_.unlock();
    }

private:
    mutex mutex1_;
    mutex mutex2_;
};
