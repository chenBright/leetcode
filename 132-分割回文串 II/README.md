# 132-分割回文串 II

## 题目

leetcode：[132-分割回文串 II](https://leetcode-cn.com/problems/palindrome-partitioning-ii/)

## 动态规划

参考[博客](https://github.com/grandyang/leetcode/issues/132)。

### 实现1

```c++
class Solution {
public:
    int minCut(string s) {
        if (s.empty()) {
            return 0;
        }

        int length = s.size();
        vector<vector<bool> > dp1(length, vector<bool>(length, false));
        vector<int> dp2(length);
        for (int i =0; i < length; ++i) {
            dp2[i] = i; // 分割成 i + 1 个字母
            for (int j = 0; j <= i; ++j) {
                if (s[i] ==s[j] && (i - j < 2 || dp1[j + 1][i - 1])) {
                    dp1[j][i] = true;
                    // j == 0，即 [0 ... i] 是回文字符串，则不需要分割，为 0；
                    // 否则，在
                    // - 已经找到的 [0 ... i] 最小分割方案；
                    // - [0 ... j - 1]、[j ... i] 分割方案；
                    // 中，去最小的方案。
                    dp2[i] = j == 0 ? 0 : min(dp2[i], dp2[j - 1] + 1);
                }
            }
        }

        return dp2[length - 1];
    }
};
```

### 实现2

```c++
class Solution {
public:
    int minCut(string s) {
        if (s.empty()) {
            return 0;
        }

        int length = s.size();
        // dp[i] 表示由s串中前 i 个字母的最小分割方案。
        vector<int> dp(length + 1, INT_MAX);
        dp[0] = -1;
        for (int i = 0; i < length; ++i) {
            // 回文字符串的字符数是奇数的情况
            // 以 i 为中心向两边扩展
            for (int len = 0; i - len >= 0 && i + len < length && s[i - len] == s[i + len]; ++len) {
                // 扩展到 i + len + 1，可以确定 [i - len ... i + len + 1] 是回文字符串。
                // - 已经找到的 [0 ... i + len + 1] 最小分割方案；
                // - [0 ... i - len - 1]、[i - len ... i + len + 1] 分割方案；
                // 中，去最小的方案。
                dp[i + len + 1] = min(dp[i + len + 1], dp[i - len] + 1);
            }

            // 回文字符串的字符数是偶数的情况
            // 以 i，i + 1 为中心向两边扩展
            for (int len = 0; i - len >= 0 && i + len + 1 < length && s[i - len] == s[i + len + 1]; ++len) {
                // 扩展到 i + len + 2，可以确定 [i - len ... i + len + 2] 是回文字符串。
                // - 已经找到的 [0 ... i + len + 2] 最小分割方案；
                // - [0 ... i - len - 1]、[i - len ... i + len + 2] 分割方案；
                // 中，去最小的方案。
                dp[i + len + 2] = min(dp[i + len + 2], dp[i - len] + 1);
            }
        }

        return dp[length];
    }
};
```

