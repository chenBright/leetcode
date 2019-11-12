#include <functional>
#include <pthread.h>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    pthread_mutex_t mutex_;
    pthread_cond_t cond_;
    unsigned int flag;

public:
    ZeroEvenOdd(int n) : flag(0) {
        this->n = n;

        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&cond_, nullptr);
    }

    ~ZeroEvenOdd() {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&cond_);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            pthread_mutex_lock(&mutex_);
            while (flag != 0) {
                pthread_cond_wait(&cond_, &mutex_);
            }

            printNumber(0);
            if (i % 2 == 1) {
                flag = 1;
            } else {
                flag = 2;
            }
            pthread_mutex_unlock(&mutex_);
            pthread_cond_signal(&cond_);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            pthread_mutex_lock(&mutex_);
            while (flag != 2) {
                pthread_cond_wait(&cond_, &mutex_);
            }
            printNumber(i);
            flag = 0;
            pthread_mutex_unlock(&mutex_);
            pthread_cond_signal(&cond_);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            pthread_mutex_lock(&mutex_);
            while (flag != 1) {
                pthread_cond_wait(&cond_, &mutex_);
            }
            printNumber(i);
            flag = 0;
            pthread_mutex_unlock(&mutex_);
            pthread_cond_signal(&cond_);
        }    
    }
};
