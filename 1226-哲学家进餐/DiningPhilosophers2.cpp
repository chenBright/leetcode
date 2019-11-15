#include <functional>
#include <mutex>
using namespace std;

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