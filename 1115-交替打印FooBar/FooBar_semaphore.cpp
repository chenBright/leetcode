#include <functional>
#include <semaphore.h>
using namespace std;

class FooBar {
private:
    int n;
    sem_t sem1_;
    sem_t sem2_;

public:
    FooBar(int n) {
        this->n = n;

        // 将信号量值初始化为 0
        sem_init(&sem1_, 0, 1);
        sem_init(&sem2_, 0, 0);
    }

    ~FooBar() {
        // 销毁信号量
        sem_destroy(&sem1_);
        sem_destroy(&sem2_);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&sem1_);

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            sem_post(&sem2_);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&sem2_);
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            sem_post(&sem1_);
        }
    }
};
