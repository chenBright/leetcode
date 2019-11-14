#include <functional>
#include <mutex>
using namespace std;

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