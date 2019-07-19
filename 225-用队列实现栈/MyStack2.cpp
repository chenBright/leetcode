#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    // 将元素队列中原有元素拷贝到辅助队列中，
    // 将 x 压入元素队列，再将辅助队列中的元素拷贝回元素队列，
    // 这样，队列中元素的队头到队尾顺序跟栈的顺序一样
    // 时间复杂度：O(n)
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
        } else {
            q2 = q1;
            while (!q1.empty()) {
                q1.pop();
            }
            q1.push(x);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    // 队头元素就是栈顶元素
    // 时间复杂度：O(1)
    int pop() {
        int result = q1.front();
        q1.pop();
        
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1; // 保存元素的队列
    queue<int> q2; // 辅助队列
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */