# 946-验证栈序列

## 题目

leetcode：[946-验证栈序列](https://leetcode-cn.com/problems/validate-stack-sequences/)

## 模拟栈操作

```c++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for (const auto& p : pushed) {
            s.push(p);
            while (!s.empty() && j < popped.size() && s.top() == popped[j]) {
                s.pop();
                ++j;
            }
        }

        return s.empty();
    }
};
```

