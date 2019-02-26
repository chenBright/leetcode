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
        if (s.size() % 2 != 0) {
            return false;
        }

        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) { // 栈内没有左括号与右括号匹配
                    return false;
                } else {
                    if (ch == ')') {
                        if (st.top() == '(') {
                            st.pop();
                        } else {
                            return false;
                        }
                    } else if (ch == ']') {
                        if (st.top() == '[') {
                            st.pop();
                        } else {
                            return false;
                        }
                    } else if (ch == '}') {
                        if (st.top() == '{') {
                            st.pop();
                        } else {
                            return false;
                        }
                    }
                }
            }
        }

        return st.empty() ? true : false;
    }
};
```

