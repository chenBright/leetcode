#include <functional>
#include <thread>
#include <atomic>
using namespace std;

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
