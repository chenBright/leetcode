#include <functional>
#include <mutex>
using namespace std;

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