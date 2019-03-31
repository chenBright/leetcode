# 062-不同路径

## 题目

leetcode：[062-不同路径](https://leetcode-cn.com/problems/unique-paths/)


## 递归

递归实现效率不高，在LeetCode上会"超出时间限制"。

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 && n == 0) {
            return 0;
        }

        return uniquePaths(0, 0, n - 1, m - 1);
    }

private:
    int uniquePaths(int i, int j, int maxI, int maxJ) {
        if (i > maxI || j > maxJ) { // 已经走出网格的最大范围
            return 0;
        } else if (i == maxI && j == maxJ) { // 已经走到终点
            return 1;
        } else if (i == maxI || j == maxJ) { // 已经做到与终点在同一条边上，只剩一条路可以到达终点
            return 1;
        }

        return uniquePaths(i + 1, j, maxI, maxJ) + uniquePaths(i, j + 1, maxI, maxJ);
    }
};
```

## 动态规划

使用***二维数组dp***记录路径数，***dp\[i\]\[j\]表示\[0\]\[0\]到\[i\]\[j\]存在多少条路径***。

1. 如果***i == 0***或者***j == 0***，因为只有一条路径到达这些网格，所以***dp\[i\]\[j\] = 1***。
2. 其他网格，可以来自两个方向（来自上边或者左边），所以***dp\[i\]\[j\] = dp\[i - 1\]\[j\] + dp\[i\]\[j - 1\]***，即等于这两个方向的路径数之和。

动态规划的时间复杂度为***O(mn)***。

```c++
class Solution {
public:
    // m表示列，n表示行
    int uniquePaths(int m, int n) {
        if (m == 0 && n == 0) {
            return 0;
        }

        /** dp[i][j]表示从[0][0]到[i][j]存在多少条路径
         * 初始化为1，表示至少有1中路径
         */
        vector<vector<int> > dp(n, vector<int>(m, 1));
        // i == 0 和 j == 0，只有一条路径到达这些网格，初始化dp时已处理
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};
```

## 组合数

机器人一定会走***m + n - 2***步，即向下走***m - 1***步，向右走***n - 1***步。机器人从***m + n - 2***步中挑***m - 1***步向下走或者挑***n - 1***步向右走，即***C((m + n - 2), (m - 1))***或者***C((m + n - 2), (n - 1))***。其实两个数相等，例如***C(12, 9) 等于 C(12, 3)***。

的时间复杂度为***O(m)***。

```c++
class Solution {
public:
    // m表示列，n表示行
    int uniquePaths(int m, int n) {
        /**
         * 机器人一定会走 m + n - 2 步，即向下走 m - 1 步，向右走 n - 1 步。
         * 机器人从 m + n - 2 步中挑 m - 1 步向下走或者挑 n - 1 步向右走，
         * 即 C((m + n - 2), (m - 1))或者 C((m + n - 2), (n - 1))。
         * 其实两个数相等，例如 C(12, 9) 等于 C(12, 3)。
         */
        return combinationNum(m + n - 2, m - 1);
        // return combinationNum(m + n - 2, n - 1);
    }

private:
    // 计算组合数
    int combinationNum(int n, int k) {
        long long res = 1;
        if (k > n - k) {
            k = n - k;
        }
        for (int i = n, x = 1; i > n - k; --i, ++x) {
            /** 
             * 参考 http://kuangqi.me/programming/combination-calculation/
             * 由于用到了阶乘，极容易导致数据溢出，应用中应采用边乘边除的方法。
             * 除法一般需要用到浮点数，但通过数论中的定理，可以通过整数运算实现。
             */
            res *= i;
            res /= x;
        }

        return static_cast<int>(res);
    }
};
```