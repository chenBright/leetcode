# 064-最小路径和

## 题目

leetcode：[064-最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)


## 动态规划

解法与[062-不同路径](https://leetcode-cn.com/problems/unique-paths/)大致相同。

- 如果该网格是起点，则***dp\[i\]\[j\] = grid\[i\]\[j\]***。
- 如果该网格是第一行的网格（除了起点），该网格只能从左边走过来，则***dp\[i\]\[j\] = dp\[i\]\[j - 1\] + grid\[i\]\[j\]***。
- 如果该网格是第一列的网格（除了起点），该网格只能从上边走过来，则***dp\[i\]\[j\] = dp\[i - 1\]\[j \] + grid\[i\]\[j\]***。
- 其他，该网格能从两个方向走到该网格，取两个方向的最小值，再加上该网格的值，即为从起点到该网格的最小路径和，则***dp\[i\]\[j\] = min(dp\[i - 1\]\[j \] + dp\[i\]\[j - 1\]) + grid\[i\]\[j\]***。

动态规划的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size(); // 行
        int m = grid[0].size(); // 列

        if (m == 0 || n == 0) {
            return 0;
        }

        /**
         * dp[i][j]示从[0][0]到[i][j]最小路径和
         */
        vector<vector<int> > dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) { // 起点
                    dp[i][j] = grid[i][j];
                } else if (i == 0) { // 第一行
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                } else if (j == 0) { // 第一列
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
```

## 最短路径算法

题目给定的网格，可以构建一个无权有向图。结点为数组元素：

- 如果是终点，不指向任何结点。
- 如果是最后一行的网格（除了终点），只指向右边的结点。
- 如果是最后一列的网格（除了终点），只指向下边的结点。
- 其他，指向右边的结点和下边的结点。

在构建好的无权有向图上，使用最短路径算法找出最小路径和即可。

TODO