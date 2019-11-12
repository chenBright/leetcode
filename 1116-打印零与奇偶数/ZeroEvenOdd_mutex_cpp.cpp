#include <functional>
#include <mutex>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    mutex zeroMutex_;
    mutex evenMutex_;
    mutex oddMutex_;

public:
    ZeroEvenOdd(int n) {
        this->n = n;

        evenMutex_.lock();
        oddMutex_.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            zeroMutex_.lock();
            printNumber(0);
            if (i % 2 == 1) {
                oddMutex_.unlock();
            } else {
                evenMutex_.unlock();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            evenMutex_.lock();
            printNumber(i);
            zeroMutex_.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            oddMutex_.lock();
            printNumber(i);
            zeroMutex_.unlock();
        }    
    }
};
