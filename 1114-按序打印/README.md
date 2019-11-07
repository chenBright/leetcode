# 1114-按序打印

## 题目

leetcode：[1114-按序打印](https://leetcode-cn.com/problems/print-in-order/)

## pthread 互斥量

使用两个互斥量`mutex1_`、`mutex2_`。在构造函数中初始化两个互斥量后，立即对两个互斥量上锁。

1. 在对两个互斥量上锁时，只允许线程A调用函数。调用完函数后，解锁`mutex1_`。
2. 线程B获取`mutex1_`后，调用函数。调用完函数后，解锁`mutex1_`、`mutex2_`。
3. 线程C获取`mutex2_`后，调用函数。调用完函数后，解锁`mutex2_`。

```c++
class Foo {
public:
    Foo() {
        // 初始化互斥量
        pthread_mutex_init(&mutex1_, nullptr);
        pthread_mutex_init(&mutex2_, nullptr);

        // 上锁
        pthread_mutex_lock(&mutex1_);
        pthread_mutex_lock(&mutex2_);
    }

    ~Foo() {
        // 销毁互斥量
        pthread_mutex_destroy(&mutex1_);
        pthread_mutex_destroy(&mutex2_);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        // 解锁 mutex1_
        pthread_mutex_unlock(&mutex1_);
    }

    void second(function<void()> printSecond) {
        // 对 mutex1_ 上锁
        pthread_mutex_lock(&mutex1_);

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        // 解锁 mutex2_
        pthread_mutex_unlock(&mutex2_);

        pthread_mutex_unlock(&mutex1_);
    }

    void third(function<void()> printThird) {
        // 对 mutex2_ 上锁
        pthread_mutex_lock(&mutex2_);
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();

        // 解锁 mutex2_
        pthread_mutex_unlock(&mutex2_);
    }

private:
    pthread_mutex_t mutex1_;
    pthread_mutex_t mutex2_;
};
```

## pthread 条件变量

与使用“互斥量”的方法类似，使用两个变量来控制访问顺序。当一个线程完成函数调用后，才改变下一个线程依赖的变量，使其不再等在条件变量上。

但该方法***超时***了。

```c++
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
```

## pthread 信号量

思想同前面两种方法。

```c++
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
```

## 无锁

使用变量`flag`表示当前可以访问的函数。

1. 当`flag == 1`时，可以调用`first`函数，最后将`flag`设置为2。
2. 当`flag == 2`时，可以调用`first`函数，最后将`flag`设置为3。
3. 当`flag == 3`时，可以调用`first`函数。

线程使用的策略的***忙等待***，知道`flag`等于期望值才去调用打印函数。所以，该方法效率很低。

```c++
class Foo {
public:
    Foo() : flag(1) {
    }

    ~Foo() {
    }

    void first(function<void()> printFirst) {
        while(flag != 1);
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        ++flag;
    }

    void second(function<void()> printSecond) {
        while(flag != 2);

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        ++flag;
    }

    void third(function<void()> printThird) {
        while(flag != 3);
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    volatile int flag;
};
```

