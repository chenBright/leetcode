# 1115-交替打印FooBar

## 题目

leetcode：[1115-交替打印FooBar](https://leetcode-cn.com/problems/print-foobar-alternately/)

## 互斥量

### pthread

```c++
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
```

### C++

```c++
class FooBar {
private:
    int n;
    mutex mutex1_;
    mutex mutex2_;

public:
    FooBar(int n) {
        this->n = n;

        mutex2_.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            mutex1_.lock();

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            mutex2_.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            mutex2_.lock();
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            mutex1_.unlock();
        }
    }
};
```

## 条件变量

### pthread

```c++
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
```

### C++

```c++
class FooBar {
private:
    int n;
    mutex mutex_;
    condition_variable cond_;
    bool flag;

public:
    FooBar(int n) : flag(true) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
        unique_lock<mutex> lock(mutex_);
            while (flag != true) {
                cond_.wait(lock);
            }

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            flag = false;
            cond_.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
        unique_lock<mutex> lock(mutex_);
            while (flag != false) {
                cond_.wait(lock);
            }
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            flag = true;
            cond_.notify_all();
        }
    }
};
```

## pthread 信号量

```c++
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
```

## 无锁

### 实现1

因为忙等待的效率太低了，该实现***超时***了。

```c++
class FooBar {
private:
    int n;
    volatile int count;

public:
    FooBar(int n) : count(1) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while (count % 2 != 1);

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            ++count;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while (count % 2 != 0);
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            ++count;
        }
    }
};
```

### 原子操作

```c++
class FooBar {
private:
    int n;
    atomic<bool> flag;

public:
    FooBar(int n) {
        this->n = n;
        flag.store(true, memory_order_relaxed);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            if (flag.load(memory_order_relaxed)) {

                // printFoo() outputs "foo". Do not change or remove this line.
                printFoo();

                flag.store(false, memory_order_release);
                ++i;
            }
            this_thread::yield(); // 将当前线程的 CPU 时间让渡给其他线程。
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            if (!flag.load(memory_order_relaxed)) {
            
                // printBar() outputs "bar". Do not change or remove this line.
                printBar();

                flag.store(true, memory_order_release);
                ++i;
            }
            this_thread::yield(); // 将当前线程的 CPU 时间让渡给其他线程。
        }
    }
};
```

