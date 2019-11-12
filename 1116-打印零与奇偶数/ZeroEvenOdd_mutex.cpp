#include <functional>
#include <pthread.h>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    pthread_mutex_t zeroMutex_;
    pthread_mutex_t evenMutex_;
    pthread_mutex_t oddMutex_;

public:
    ZeroEvenOdd(int n) {
        this->n = n;

        pthread_mutex_init(&zeroMutex_, nullptr);
        pthread_mutex_init(&evenMutex_, nullptr);
        pthread_mutex_init(&oddMutex_, nullptr);

        pthread_mutex_lock(&evenMutex_);
        pthread_mutex_lock(&oddMutex_);
    }

    ~ZeroEvenOdd() {
        pthread_mutex_destroy(&evenMutex_);
        pthread_mutex_destroy(&oddMutex_);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            pthread_mutex_lock(&zeroMutex_);
            printNumber(0);
            if (i % 2 == 1) {
                pthread_mutex_unlock(&oddMutex_);
            } else {
                pthread_mutex_unlock(&evenMutex_);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            pthread_mutex_lock(&evenMutex_);
            printNumber(i);
            pthread_mutex_unlock(&zeroMutex_);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            pthread_mutex_lock(&oddMutex_);
            printNumber(i);
            pthread_mutex_unlock(&zeroMutex_);
        }    
    }
};
