# 232-用栈实现队列

## 题目

leetcode：[232-用栈实现队列](https://leetcode-cn.com/problems/implement-queue-using-stacks/)

## 参考

解析见[LeetCode官方题解](https://leetcode-cn.com/problems/implement-queue-using-stacks/solution/yong-zhan-shi-xian-dui-lie-by-leetcode)。

## 使用两个栈 入队 - O(n)， 出队 - O(1)

```c++
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
        moveToAnother(popStack, pushStack);
        popStack.push(x);
        moveToAnother(pushStack, popStack);
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

    // 将元素从 src 栈移动到 des栈
    void moveToAnother(stack<int> &src, stack<int> &des) {
        while (!src.empty()) {
            des.push(src.top());
            src.pop();
        }
    }
};
```

## 使用两个栈 入队 - O(1)，出队 - 摊还复杂度 O(1)

```c++
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    // 时间复杂度为 O(1)
    void push(int x) {
        pushStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    // 将 pushStack 中的元素依次弹出，再压入 popStack 中，
    // 最终， popStack 从栈顶往下，就是元素入队的顺序
    // 最好情况下的时间复杂度为 O(1)
    // 最坏情况下的时间复杂度为 O(n)
    // 平均时间复杂度为 O(1)，分析见 LeetCode 官方题解方法二分析
    // https://leetcode-cn.com/problems/implement-queue-using-stacks/solution/yong-zhan-shi-xian-dui-lie-by-leetcode
    int pop() {
        if (popStack.empty()) {
            moveToAnother(pushStack, popStack);
        }
        int result = popStack.top();
        popStack.pop();

        return result;
    }
    
    /** Get the front element. */
    // 时间复杂度为 O(n)
    int peek() {
        // 如果 popStack 为空，
        // 则需要将 pushStack 中的元素弹出，再压入到 popStack 中
        if (popStack.empty()) {
            moveToAnother(pushStack, popStack);
        }

        return popStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return pushStack.empty() && popStack.empty();
    }

private:
    stack<int> pushStack; // 保存入队元素
    stack<int> popStack; // 存储的元素从栈顶往下，和元素入队的顺序一样

    // 将元素从 src 栈移动到 des栈
    void moveToAnother(stack<int> &src, stack<int> &des) {
        while (!src.empty()) {
            des.push(src.top());
            src.pop();
        }
    }
};
```

