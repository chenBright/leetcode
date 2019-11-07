#include <functional>
#include <pthread.h>
using namespace std;

class Foo {
public:
    Foo() {
        // 初始化互斥量
        pthread_mutex_init(&mutex1_, nullptr);
        pthread_mutex_init(&mutex2_, nullptr);

        // 上锁
        pthread_mutex_lock(&mutex1_);
        pthread_mutex_lock(&mutex2_);
    }

    ~Foo() {
        // 销毁互斥量
        pthread_mutex_destroy(&mutex1_);
        pthread_mutex_destroy(&mutex2_);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        // 解锁 mutex1_
        pthread_mutex_unlock(&mutex1_);
    }

    void second(function<void()> printSecond) {
        // 对 mutex1_ 上锁
        pthread_mutex_lock(&mutex1_);

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        // 解锁 mutex2_
        pthread_mutex_unlock(&mutex2_);

        pthread_mutex_unlock(&mutex1_);
    }

    void third(function<void()> printThird) {
        // 对 mutex2_ 上锁
        pthread_mutex_lock(&mutex2_);
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();

        // 解锁 mutex2_
        pthread_mutex_unlock(&mutex2_);
    }

private:
    pthread_mutex_t mutex1_;
    pthread_mutex_t mutex2_;
};
