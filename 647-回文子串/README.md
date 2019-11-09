# 647-回文子串

## 题目

leetcode：[647-回文子串](https://leetcode-cn.com/problems/palindromic-substrings/)

## 迭代

参考[博客 解法一](https://github.com/grandyang/leetcode/issues/647)。

时间复杂度：***O(n^2)***。

```c++
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) {
            return 0;
        }

        int length = s.size();
        int result = 0;
        for (int i = 0; i < length; ++i) {
            helper(s, i, i, result);
            helper(s, i, i + 1, result);
        }

        return result;
    }
private:
    void helper(string s, int i, int j, int& result) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
            ++result;
        }
    }
};
```

## 动态规划

参考[博客 解法二](https://github.com/grandyang/leetcode/issues/647)。

时间复杂度：***O(n^2)***。

空间复杂度：***O(n^2)***。

```c++
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) {
            return 0;
        }

        int length = s.size();
        int result = 0;
        vector<vector<bool> > dp(length, vector<bool>(length, false));

        for (int i = length - 1; i >= 0; --i) {
            for (int j = i; j < length; ++j) {
                // 根据 [i + 1 ... j - 1] 判断 [i ... j] 是不是回文子串
                dp[i][j] = s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]);
                if (dp[i][j]) {
                    ++result;
                }
            }
        }

        return result;
    }
};
```

