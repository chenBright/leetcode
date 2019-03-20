#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        dataStack.push(x);
        if (minStack.empty() || x <= getMin()) {
            minStack.push(x);
        }
    }
    
    void pop() {
        if (!minStack.empty() && dataStack.top() == getMin()) {
            minStack.pop();
        }
        if (!dataStack.empty()) {
            dataStack.pop();
        }
    }
    
    int top() {
        if (!dataStack.empty()) {
            return dataStack.top();
        }

        return -1;
    }
    
    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }

        return -1;
    }

private:
    stack<int> dataStack; // 储存数据的栈
    stack<int> minStack; // 存储最小值得栈
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */