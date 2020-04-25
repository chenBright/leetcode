# 032-最长有效括号

## 题目

leetcode：[032-最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)

## 栈

参考[LeetCode官方题解方法3](https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/)。

```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int start = 0;
        stack<int> indexStack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                indexStack.push(i);
            } else if (s[i] == ')') {
                if (indexStack.empty()) {
                    // 不匹配
                    start = i + 1;
                } else {
                    indexStack.pop();
                    // 更新括号匹配长度
                    // i - (indexStack.top() + 1) + 1 = i - indexStack.top()，其中s[indexStack.top() + 1] 与 s[i] 匹配
                    result = indexStack.empty() ? max(result, i - start + 1) : max(result, i - indexStack.top());
                }
            }
        }

        return result;
    }
};
```

## 动态规划

参考[LeetCode官方题解方法2](https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/)。

```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int length = s.size();
        vector<int> dp(length, 0);

        for (int i = 1; i < length; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            result = max(result, dp[i]);
        }

        return result;
    }
};
```

## 不需要额外的空间

参考[LeetCode官方题解方法4](https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/)。

在`(()`这种情况下，从左到右遍历完了，`left > right`，不会更新`result`，所以需要从右到左遍历一遍。

```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++left;
            } else if (s[i] == ')') {
               ++right;
            }
            if (left == right) {
                result = max(result, right * 2);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = right = 0;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (s[j] == '(') {
                ++left;
            } else if (s[j] == ')') {
                ++right;
            }
            if (left == right) {
                result = max(result, left * 2);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return result;
    }
};
```
