#include <functional>
#include <thread>
#include <atomic>
using namespace std;

class ZeroEvenOdd {
private:
    enum class State {ZERO_ODD, ZERO_EVEN, ODD, EVEN};
    int n;
    int id;
    atomic<State> state;


public:
    ZeroEvenOdd(int n) : id(1) {
        this->n = n;
        state.store(State::ZERO_ODD, memory_order_relaxed);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n;) {
            State s;
            if ((s = state.load(memory_order_relaxed)) == State::ZERO_ODD) {
                printNumber(0);
                state.store(State::ODD, memory_order_relaxed);
                ++i;
            } else if (state == State::ZERO_EVEN) {
                printNumber(0);
                state.store(State::EVEN, memory_order_relaxed);
                ++i;
            }
            this_thread::yield();
        }
    }

    void even(function<void(int)> printNumber) {
        while (id <= n) {
            if (state.load(memory_order_relaxed) == State::EVEN) {
                printNumber(id++);
                state.store(State::ZERO_ODD, memory_order_relaxed);
            }
            this_thread::yield();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (id <= n) {
            if (state.load(memory_order_relaxed) == State::ODD) {
                printNumber(id++);
                state.store(State::ZERO_EVEN, memory_order_relaxed);
            }
            this_thread::yield();
        }
    }
};
