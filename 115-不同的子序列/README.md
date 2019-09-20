# 115-不同的子序列

## 题目

leetcode：[115-不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)

## 动态规划

参考[博客]([https://blog.pwrliang.com/2019/02/25/115-%E4%B8%8D%E5%90%8C%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97/](https://blog.pwrliang.com/2019/02/25/115-不同的子序列/))和[LeetCode题解](https://leetcode-cn.com/problems/distinct-subsequences/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-27/)。

### 实现

```c++
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        // dp[0][j] 与 dp[i][0] 表示空串
        // dp[i, j] 表示 s[0 ... i] 与 t[0 ... j] 的匹配个数
        vector<vector<long> > dp(m + 1, vector<long>(n + 1, 0));

        // 如果 s 为空串，则一定是 t 的子序列
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }

        // 如果 t 为空串，（除了 s 也为 空串）不是 s 的空串。
        // 所以初始化为 0。（在 dp 创建的时候已完成初始化为 0 的工作）

        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                // dp[i - 1][j] 表示 s[0 ... i - 1] 与 t[0 ... j] 的匹配个数。
                // dp[i - 1][j - 1] 表示 s[0 ... i - 1] 与 t[0 ... j - 1] 的匹配个数。
                // 如果 s[i - 1] == t[j - 1]，则在 s[0 ... i - 1] 与 t[0 ... j - 1] 的匹配子序列后
                // 增加 s[i]（t[j]），也是匹配的，所以要加 dp[i - 1][j - 1]。
                dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }

        return dp[m][n];
    }
};

```

### 优化

```c++
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        // dp[0][j] 与 dp[i][0] 表示空串
        // dp[i, j % 2] 表示 s[0 ... i] 与 t[0 ... j] 的匹配个数
        // 根据实现 1 可知，
        vector<vector<long> > dp(m + 1, vector<long>(2, 0));

        // 如果 s 为空串，则一定是 t 的子序列
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }

        // 如果 t 为空串，（除了 s 也为 空串）不是 s 的空串。
        // 所以初始化为 0。（在 dp 创建的时候已完成初始化为 0 的工作）

        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                // dp[i - 1][j] 表示 s[0 ... i - 1] 与 t[0 ... j] 的匹配个数。
                // dp[i - 1][j - 1] 表示 s[0 ... i - 1] 与 t[0 ... j - 1] 的匹配个数。
                // 如果 s[i - 1] == t[j - 1]，则在 s[0 ... i - 1] 与 t[0 ... j - 1] 的匹配子序列后
                // 增加 s[i]（t[j]），也是匹配的，所以要加 dp[i - 1][j - 1]。
                dp[i][j % 2] = dp[i - 1][j % 2] + (s[i - 1] == t[j - 1] ? dp[i - 1][(j - 1) % 2] : 0);
            }

            // 清理前一列被用过的结果
            for (int i = 0; i <= m; ++i) {
                dp[i][(j - 1) % 2] = 0;
            }
        }

        return max(dp[m][0], dp[m][1]);
    }
};
```

### 再优化

TODO：参考博客，将数组压缩到一维数组。

## 分治

参考[LeetCode题解](https://leetcode-cn.com/problems/distinct-subsequences/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-27/)。

```c++
class Solution {
public:
    int numDistinct(string s, string t) {
        return numDistinct(s, 0, t, 0);
    }

private:
    int numDistinct(string &s, int sIndex, string &t, int tIndex) {
        // T 是空串，选法就是 1 种
        if (tIndex == t.size()) {
            return 1;
        }

        // S 是空串，选法是 0 种
        if (sIndex == s.size()) {
            return 0;
        }

        // 如果 s[sIndex] == t[tIndex]，则
        // 1. 在 s[sIndex + 1 ... sLen - 1] 中选出 t[tIndex + 1 ... tLen - 1]，记为 n1；
        // 2. 在 s[sIndex + 1 ... sLen - 1] 中选出 t[tIndex ... tLen - 1]，记为 n2。
        // 最后结果为 n1 + n2。
        // 如果 s[sIndex] == t[tIndex]，则在 s[sIndex + 1 ... sLen - 1] 中选出 t[tIndex ... tLen - 1]。
        if (s[sIndex] == t[tIndex]) {
            return numDistinct(s, sIndex + 1, t, tIndex + 1)
                 + numDistinct(s, sIndex + 1, t, tIndex);
        } else {
            return numDistinct(s, sIndex + 1, t, tIndex);
        }
    }
};
```

该方法存在大量的重复计算。当`s`很长的时候，会***超时***。应对递归中大量到的重复计算，使用一个变量来缓存计算结果即可解决问题。这里使用二维数组``memory`来缓存计算结果，其中`memory[i][j]`表示`s[i ... sLen - 1]`中`t[j ... tLen - 1]`的个数。

```c++
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int> > memory(s.size(), vector<int>(t.size(), -1));
        return numDistinct(s, 0, t, 0, memory);
    }

private:
    int numDistinct(string &s, int sIndex, string &t, int tIndex, vector<vector<int> > &memory) {
        // T 是空串，选法就是 1 种
        if (tIndex == t.size()) {
            return 1;
        }

        // S 是空串，选法是 0 种
        if (sIndex == s.size()) {
            return 0;
        }

        if (memory[sIndex][tIndex] != -1) {
            return memory[sIndex][tIndex];
        }

        // 如果 s[sIndex] == t[tIndex]，则
        // 1. 在 s[sIndex + 1 ... sLen - 1] 中选出 t[tIndex + 1 ... tLen - 1]，记为 n1；
        // 2. 在 s[sIndex + 1 ... sLen - 1] 中选出 t[tIndex ... tLen - 1]，记为 n2。
        // 最后结果为 n1 + n2。
        // 如果 s[sIndex] == t[tIndex]，则在 s[sIndex + 1 ... sLen - 1] 中选出 t[tIndex ... tLen - 1]。
        int count = 0;
        if (s[sIndex] == t[tIndex]) {
            count = numDistinct(s, sIndex + 1, t, tIndex + 1, memory);
        }
        count += numDistinct(s, sIndex + 1, t, tIndex, memory);

        memory[sIndex][tIndex] = count;

        return count;
    }
};
```

## 回溯法

TODO：参考[博客]([https://blog.pwrliang.com/2019/02/25/115-%E4%B8%8D%E5%90%8C%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97/](https://blog.pwrliang.com/2019/02/25/115-不同的子序列/))和[LeetCode题解](https://leetcode-cn.com/problems/distinct-subsequences/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-27/)。

