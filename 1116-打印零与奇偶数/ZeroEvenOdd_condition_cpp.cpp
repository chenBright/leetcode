#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    mutex mutex_;
    condition_variable cond_;
    unsigned int flag;

public:
    ZeroEvenOdd(int n) : flag(0) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            unique_lock<mutex> lock(mutex_);
            while (flag != 0) {
                cond_.wait(lock);
            }

            printNumber(0);
            if (i % 2 == 1) {
                flag = 1;
            } else {
                flag = 2;
            }
            cond_.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mutex_);
            while (flag != 2) {
                cond_.wait(lock);
            }

            printNumber(i);
            flag = 0;
            cond_.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mutex_);
            while (flag != 1) {
                cond_.wait(lock);
            }

            printNumber(i);
            flag = 0;
            cond_.notify_all();
        }    
    }
};
