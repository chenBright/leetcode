#include <functional>
using namespace std;

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
