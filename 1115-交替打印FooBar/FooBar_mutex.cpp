#include <functional>
#include <pthread.h>
using namespace std;

class FooBar {
private:
    int n;
    pthread_mutex_t mutex1_;
    pthread_mutex_t mutex2_;

public:
    FooBar(int n) {
        this->n = n;

        pthread_mutex_init(&mutex1_, nullptr);
        pthread_mutex_init(&mutex2_, nullptr);

        pthread_mutex_unlock(&mutex2_);
    }

    ~FooBar() {
        // 销毁互斥量
        pthread_mutex_destroy(&mutex1_);
        pthread_mutex_destroy(&mutex2_);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mutex1_);

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            pthread_mutex_unlock(&mutex2_);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mutex2_);
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            pthread_mutex_unlock(&mutex1_);
        }
    }
};
