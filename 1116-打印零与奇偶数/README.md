# 1116-打印零与奇偶数

## 题目

leetcode：[1116-打印零与奇偶数](https://leetcode-cn.com/problems/print-zero-even-odd/)

## 互斥量

### pthread

```c++
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
```

### C++

```c++
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
```

## 条件变量

### pthread

```c++
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
```

### C++

```c++
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
```

