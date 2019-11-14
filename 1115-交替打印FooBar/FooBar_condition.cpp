#include <functional>
#include <pthread.h>
using namespace std;

class FooBar {
private:
    int n;
    pthread_mutex_t mutex_;
    pthread_cond_t cond_;
    bool flag;

public:
    FooBar(int n) : flag(true) {
        this->n = n;
        
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&cond_, nullptr);
    }

    ~FooBar() {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&cond_);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mutex_);
            while (flag != true) {
                pthread_cond_wait(&cond_, &mutex_);
            }

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            flag = false;
            pthread_mutex_unlock(&mutex_);
            pthread_cond_signal(&cond_);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mutex_);
            while (flag != false) {
                pthread_cond_wait(&cond_, &mutex_);
            }
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            flag = true;
            pthread_mutex_unlock(&mutex_);
            pthread_cond_signal(&cond_);
        }
    }
};
