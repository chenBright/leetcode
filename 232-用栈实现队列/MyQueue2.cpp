#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    // 1. 将 popStack 中的元素依次弹出，再压入 pushStack 中；
    // 2. 将 x 压入 popStack 中；
    // 3. 重新将 pushStack 中的元素依次弹出，再压入 popStack 中。
    // 最终， popStack 从栈顶往下，就是元素入队的顺序。
    // 时间复杂度为 O(n)
    void push(int x) {
        while (!popStack.empty()) {
            pushStack.push(popStack.top());
            popStack.pop();
        }

        popStack.push(x);

        while (!pushStack.empty()) {
            popStack.push(pushStack.top());
            pushStack.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    // 时间复杂度为 O(1)
    int pop() {
        int result = popStack.top();
        popStack.pop();

        return result;
    }
    
    /** Get the front element. */
    int peek() {
        return popStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pushStack.empty() && popStack.empty();
    }

private:
    stack<int> pushStack; // 辅助栈
    stack<int> popStack; // 存储的元素从栈顶往下，和元素入队的顺序一样
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */