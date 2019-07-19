#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    // 时间复杂度：O(1)
    void push(int x) {
        top_ = x;
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    // 将元素队列中原有元素（除队尾元素）拷贝到辅助队列中，
    // 弹出元素队列的队尾元素，再将辅助队列中的元素拷贝回元素队列，
    // 时间复杂度：O(n)
    int pop() {
        while (q1.size() > 1) {
            int tmp = q1.front();
            top_ = tmp;
            q2.push(tmp);
            q1.pop();
        }
        int result = q1.front();
        q1.pop();
        queue<int> tmp = q1;
        q1 = q2;
        q2 = tmp;

        return result;
    }
    
    /** Get the top element. */
    int top() {
        return top_;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

private:
    int top_; // 记录栈顶元素
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