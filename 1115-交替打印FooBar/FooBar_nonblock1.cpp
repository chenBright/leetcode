#include <functional>
using namespace std;

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
