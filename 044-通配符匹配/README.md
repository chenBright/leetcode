# 044-通配符匹配

## 题目

leetcode：[044-通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/)


## 回溯法

参考[博客 解法一](https://github.com/grandyang/leetcode/issues/44)。

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        int iStart = -1; // 星号匹配到 s 中的位置
        int jStart = -1; // p 中星号的位置
        while (i < s.size()) {
            if (s[i] == p[j] || p[j] == '?') { // 一对一匹配，两指针同时后移
                ++i;
                ++j;
            } else if (p[j] == '*') {
                // 假设它匹配空串，并且用 startIdx 记录 * 的位置，记录当前字符串的位置，p 后移
                iStart = i;
                jStart = j++;
            } else if (iStart >= 0) { 
                // 当前字符不匹配，并且也没有 *，回溯
                // j 回到 * 的下一个位置
                // iStart 更新到下一个位置
                // i 回到更新后的 match 
                // 这步代表用 * 匹配了一个字符
                i = ++iStart;
                j = jStart + 1;
            } else { // 字符不匹配，也没有 *，返回 false
                return false;
            }
        }

        // 将末尾多余的 * 直接匹配空串 例如 text = ab, pattern = a*******
        while (j < p.size() && p[j] == '*') {
            ++j;
        }

        return j == p.size();
    }
};
```

## 动态规划

参考[博客](https://github.com/grandyang/leetcode/issues/44)和[LeetCode题解](https://leetcode-cn.com/problems/wildcard-matching/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-9/)。

### 实现1

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 1];
            }
        }

        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (p[k - 1] == '*') {
                    dp[j][k] = dp[j - 1][k] || dp[j][k - 1];
                } else {
                    dp[j][k] = (s[j - 1] == p[k - 1] || p[k - 1] == '?') && dp[j - 1][k - 1];
                }
            }
        }

        return dp[m][n];
    }
};
```

### 实现2

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0) > 1;
    }

private:
    int helper(string &s, string &p, int i, int j) {
        if (i == s.size() && j == p.size()) {
            return 2;
        }

        if (i == s.size() && p[j] != '*') {
            return 0;
        }

        if (j == p.size()) {
            return 1;
        }

        if (s[i] == p[j] || p[j] == '?') {
            return helper(s, p, i + 1, j + 1);
        }

        if (p[j] == '*') {
            if (j + 1 < p.size() && p[j + 1] == '*') {
                return helper(s, p, i, j + 1);
            }

            for (int k = 0; k <= static_cast<int>(s.size()) - i; ++k) {
                int result = helper(s, p, i + k, j + 1);
                if (result == 0 || result == 2) {
                    return result;
                }
            }
        }

        return 1;
    }
};
```
