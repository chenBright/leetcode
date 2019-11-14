# 1226-哲学家进餐

## 题目

leetcode：[1226-哲学家进餐](https://leetcode-cn.com/problems/the-dining-philosophers/)

## 死锁的条件

1. 互斥
2. 占有并等待
3. 不可抢占
4. 循环等待

前三个条件都只是死锁存在的必要条件，但不是充分条件。这四个条件一起构成死锁的充分必要条件。

## 每次只能一个哲学家进餐

使用一个互斥量（全局锁），限制每次只能一个哲学家吃饭。本质上是同时获取所有资源，而不是分布获取资源，打破***“占有并等待”***的条件。

虽然该方法实现简单，但是效率非常低，在 LeetCode 上***超时***了。

```c++
class DiningPhilosophers {
private:
    mutex mutex_;
    
public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        lock_guard<mutex> lock(mutex_);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();  
    }
};
```

## 同时拿起左右叉子

使用一个互斥量数组表示“资源”叉子，和一个互斥量，用于限制每次只能一个哲学家尝试去拿起叉子。当哲学家同时拿起了左右叉子后，释放互斥量，允许其他哲学家去常去拿起叉子。当该哲学家吃完之后，同时放下左右叉子。

该方法也是打破***“占有并等待”***的条件。

```c++
class DiningPhilosophers {
private:
    static const int N = 5;
    mutex forkMutexs_[N];
    mutex mutex_; // 用于保护访问 forkMutexs_ 数组

public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        auto left = philosopher % N;
        auto right = (philosopher + 1) % N;

        mutex_.lock();
        lock_guard<mutex> leftLock(forkMutexs_[left]);
        lock_guard<mutex> rightLock(forkMutexs_[right]);

        pickLeftFork();
        pickRightFork();
        mutex_.unlock(); // 可以释放 forkMutexs_ 数组的互斥锁
        eat();
        putLeftFork();
        putRightFork();  
    }
};
```

## 设计进餐策略

为了防止当5个哲学家都***左手持有***其***左边的叉子*** 或 当5个哲学家都***右手持有***其***右边的叉子***，设计下面的进餐策略：序号为奇数的哲学家先拿左边的叉子，再拿右边的叉子，序号为偶数的哲学家则反过来。

该方法也是打破***“循环等待”***的条件。

```c++
class DiningPhilosophers {
private:
    static const int N = 5;
    mutex forkMutexs_[N];
    
public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        auto left = philosopher % N;
        auto right = (philosopher + 1) % N;
        
        // 索引为奇数的哲学家先拿起左边的叉子，再拿起右边的叉子。
        // 索引为偶数的哲学家则反过来。
		if ((philosopher & 1) == 1) {
            forkMutexs_[left].lock();
            forkMutexs_[right].lock();
        } else {
            forkMutexs_[right].lock();
            forkMutexs_[left].lock();
        }


        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        forkMutexs_[left].unlock();
        forkMutexs_[right].unlock();
    }
};
```

## 限制同时吃饭的人数不超过4个哲学家

最多只允许 4 个哲学家去持有叉子，可保证至少有 1 个哲学家能进餐（即获得到 2 个叉子）。
最差情况下：4 个哲学家都各自持有 1 个叉子，此时还 剩余 1 个叉子 可供使用，这 4 个哲学家中必然有 1 人能获取到这个剩余的 1 个叉子，从而手持 2 个叉子，可以进餐。即：4 个人中，1 个人有 2 个叉子，3 个人各持 1 个叉子，共计 5 个叉子。

信号量的实现见[Github](https://github.com/chenBright/code_snippets/blob/master/C%2B%2B/semaphore/README.md)。

```c++
// 信号量
class semaphore {
private:
    mutex mutex_;
    condition_variable cond_;
    int count_;

public:
    semaphore(int count = 0) : count_(count) {}

    inline void notify() {
        lock_guard<mutex> lock(mutex_);
        ++count_;
        cond_.notify_one();
    }

    inline void wait() {
        unique_lock<mutex> lock(mutex_);
        while (count_ == 0) {
            cond_.wait(lock);
        }
        --count_;
    }
};

class DiningPhilosophers {
private:
    static const int N = 5;
    mutex forkMutexs_[N];
    semaphore sem_;
    
public:
    // 限制同时吃饭的人数不超过4个人，这样总会产生两个人竞争一把叉子并竞争成功的情况，避免循环等待。
    DiningPhilosophers() : sem_(4) {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        auto left = philosopher % N;
        auto right = (philosopher + 1) % N;

        sem_.wait();
        lock_guard<mutex> leftLock(forkMutexs_[left]);
        lock_guard<mutex> rightLock(forkMutexs_[right]);

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        sem_.notify();
    }
};
```

## 参考

- LeetCode 题解：
  - [题解1](https://leetcode-cn.com/problems/the-dining-philosophers/solution/1ge-semaphore-1ge-reentrantlockshu-zu-by-gfu/)
  - [题解2](https://leetcode-cn.com/problems/the-dining-philosophers/solution/zhe-xue-jia-jiu-can-wen-ti-by-mike-meng/)

- [博客](https://blog.csdn.net/chinamen1/article/details/102740786)
- [cs241](https://cs241.apachecn.org/#/docs/43)