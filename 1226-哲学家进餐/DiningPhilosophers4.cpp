#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;

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