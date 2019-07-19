# 225-用队列实现栈

## 题目

leetcode：[225-用队列实现栈](https://leetcode-cn.com/problems/implement-stack-using-queues/)

## 参考

参考[LeetCode官方题解](https://leetcode-cn.com/problems/implement-stack-using-queues/solution/yong-dui-lie-shi-xian-zhan-by-leetcode)

## 两个队列，压入 -O(1)*O*(1)， 弹出 -O(n)*O*(*n*)

```c++
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
```

## 两个队列， 压入 - O(n)*O*(*n*)， 弹出 - O(1)*O*(1)

```c++
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
```

## 一个队列， 压入 - O(n)*O*(*n*)， 弹出 - O(1)*O*(1)

```c++
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    // 将队列中原有元素弹出再压入，
    // 这样，队列中元素的队头到队尾顺序跟栈的顺序一样
    // 时间复杂度：O(n)
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    // 队头元素就是栈顶元素
    // 时间复杂度：O(1)
    int pop() {
        int result = q.front();
        q.pop();
        
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q; // 保存元素的队列
};
```

