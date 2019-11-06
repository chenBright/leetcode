#include <functional>
#include <semaphore.h>
using namespace std;

class Foo {
public:
    Foo() {
        // 将信号量值初始化为 0
        sem_init(&sem1_, 0, 0);
        sem_init(&sem2_, 0, 0);
    }

    ~Foo() {
        // 销毁信号量
        sem_destroy(&sem1_);
        sem_destroy(&sem2_);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        sem_post(&sem1_);
    }

    void second(function<void()> printSecond) {
        sem_wait(&sem1_);

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        sem_post(&sem2_);
    }

    void third(function<void()> printThird) {
        sem_wait(&sem2_);
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    sem_t sem1_;
    sem_t sem2_;
};
