#include <functional>
#include <pthread.h>
using namespace std;

class Foo {
public:
    Foo() :  flag1(false), flag2(false) {
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&cond_, nullptr);
    }

    ~Foo() {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&cond_);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        flag1 = true;
        pthread_mutex_unlock(&mutex_);
        pthread_cond_signal(&cond_);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&mutex_);
        // 直到 falg1 == true，才能进入临界区
        while (flag1 != true) {
            pthread_cond_wait(&cond_, &mutex_);
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        flag2 = true;
        pthread_mutex_unlock(&mutex_);
        pthread_cond_signal(&cond_);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&mutex_);
        // 直到 falg1 == true && flag2 == true，才能进入临界区
        while (flag1 != true || flag2 != true) {
            pthread_cond_wait(&cond_, &mutex_);
        }
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    pthread_mutex_t mutex_;
    pthread_cond_t cond_;

    bool flag1;
    bool flag2;
};
