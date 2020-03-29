# 020-有效的括号

## 题目

leetcode：[020-有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)


## 思路
这是栈应用的经典问题，详细解释参考[LeetCode有效的括号官方解答](https://leetcode-cn.com/problems/valid-parentheses/solution/)。

## 代码

```c++
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }

        stack<int> sStack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sStack.push(s[i]);
            } else {
                if (sStack.empty()) {
                    return false;
                }

                char c = sStack.top();
                sStack.pop();
                if (s[i] == ')' && c != '(') {
                    return false;
                } else if (s[i] == ']' && c != '[') {
                    return false;
                } else if (s[i] == '}' && c != '{') {
                    return false;
                }
            }
        }

        return sStack.empty();
    }
};
```

