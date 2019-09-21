# 115-不同的子序列

## 题目

leetcode：[115-不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)

## 动态规划

参考[博客](https://blog.pwrliang.com/2019/02/25/115-不同的子序列/)和[LeetCode题解](https://leetcode-cn.com/problems/distinct-subsequences/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-27/)。

### 二维数组

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

### 压缩的二维数组

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

### 一维数组

参考[博客](https://blog.pwrliang.com/2019/02/25/115-不同的子序列/)和[LeetCode题解](https://leetcode-cn.com/problems/distinct-subsequences/solution/cong-bao-li-di-gui-dao-dong-tai-gui-hua-cong-dong-/)的思路。

### 实现1

```c++
// 行主序
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<long> dp(n + 1, 0);
        // dp[0] 表示空串，因为不管S多长，都只能找到一个空串，与T相等，所以为 1。
        dp[0] = 1; 

        // 当 S = "babgbag", T = "bag"  dp矩阵的变化情况为
        // b: 1 1 0 0
        // a: 1 1 1 0
        // b: 1 2 1 0
        // g: 1 2 1 1
        // b: 1 3 1 1  
        // a: 1 3 4 1  
        // g: 1 3 4 5
        // 
        // i 、j 是索引，所以 i < m，j < n。
        for (int i = 0; i < m; ++i) {
            // 当前 dp 的值相当于二维数组中上一行的值。
            // 从尾开始更新，防止 dp[j + 1] 被覆盖。
            for (int j = n - 1; j >= 0; --j) {
                if (t[j] == s[i]) {
                    // 相当于在二维数组中上一个值和斜对角的值相加
                    dp[j + 1] += dp[j];
                }
            }
        }

        return dp[n];
    }
};

```

### 实现2

```c++
// 行主序
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<long> dp(n + 1, 0);
        // dp[0] 表示空串，因为不管S多长，都只能找到一个空串，与T相等，所以为 1。
        dp[0] = 1; 

        // i 、j 是索引，所以 i < m，j < n。
        for (int i = 0; i < m; ++i) {
            int previous = dp[0]; // 缓存值，防止被覆盖后得不到值
            for (int j = 0; j < n; ++j) {
                int tmp = dp[j + 1];
                if (t[j] == s[i]) {
                    // 相当于在二维数组中上一个值和斜对角的值相加
                    dp[j + 1] += previous;
                }
                previous = tmp;
            }
        }

        return dp[n];
    }
};
```

### 使用字典再优化运算时间

```c++
// 行主序 + 字典
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<long> dp(n + 1, 0);
        // dp[0] 表示空串，因为不管S多长，都只能找到一个空串，与T相等，所以为 1。
        dp[0] = 1; 

        // 构造 t 的字典，当 s[i] == t[j] 时，通过 next 数组访问下一个
        vector<int> hash(128, -1);
        vector<int> next(n, -1);
        for (int i = 0; i < n; ++i) {
            int c = t[i];
            // next 存放字符 c （在 t 中）之前的位置，然后再更新 hash 的位置
            next[i] = hash[c];
            hash[c] = i;
        }

        // 当S = "babgbag", T = "baga" 时，
        // next数组为 -1  -1  -1  1  
        // （-1 表示之前在 t 中的位置为 -1，即该位置为字母第一次出现的位置。而最后一次出现的位置存储在 hash 中）
        // （遍历的时候，从后往前遍历，一直遍历到 -1 位置）
        // hash[a] = 3   hash[b] = 0   hash[g] = 2 
        // dp矩阵的变化情况为
        // b: 1 1 0 0 0 
        // a: 1 1 1 0 0  
        // b: 1 2 1 0 0
        // g: 1 2 1 1 0
        // b: 1 3 1 1 0  
        // a: 1 3 4 1 1
        // g: 1 3 4 5 1
        for (int i = 0; i < m; ++i) {
            // 降低当前 for 的时间复杂度。
            // 观察前几种动态规划解法 3、4，内循环都是在找 t[i] == s[i]。
            // 而此部分信息，已经存储在 next 中。
            for (int j = hash[s[i]]; j >= 0; j = next[j]) {
                dp[j + 1] += dp[j];
            }
        }

        return dp[n];
    }
};
```



## 回溯法

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

