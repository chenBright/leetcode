# 064-最小路径和

## 题目

leetcode：[064-最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)


## 动态规划

解法与[062-不同路径](https://leetcode-cn.com/problems/unique-paths/)大致相同。

## 二维数组

该方法是从终点倒着走走回起点，后面想了想，其实从起点走到终点（可以相互替换）也是一样的。

- 如果该网格是终点，则`dp[i][j] = grid[i][j]`。
- 如果该网格是最后一行的网格（除了终点），该网格只能从左边走过来，则`dp[i][j] = dp[i][j + 1] + grid[i][j]`。
- 如果该网格是最后一列的网格（除了终点），该网格只能从上边走过来，则`dp[i][j] = dp[i - 1][j] + grid[i][j]`。
- 其他，该网格能从两个方向走到该网格，取两个方向的最小值，再加上该网格的值，即为从起点到该网格的最小路径和，则`dp[i][j] = min(dp[i - 1][j] + dp[i][j - 1]) + grid[i][j]`。

时间复杂度为**O(mn)**，其中 m、n 分别为二维数组的长和宽。
空间复杂度为**O(mn)**。

```c++
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if (grid.empty()) {
            return 0;
        }

        int row = grid.size();      // 行
        int col = grid[0].size();   // 列

        // dp[i][j] 示从 [i][j] 到 [row - 1][col - 1] 最小路径和。
        vector<vector<int> > dp(row, vector<int>(col, 0));
        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                if (i == row - 1 && j == col - 1) { // 终点
                    dp[i][j] = grid[i][j];
                } else if (i == row - 1) { // 最后一行
                    dp[i][j] = dp[i][j + 1] + grid[i][j];
                } else if (j == col - 1) { // 最后一列
                    dp[i][j] = dp[i + 1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
                }
            }
        }

        return dp[0][0];
    }
};
```

### 一维数组

可以将二维数组压缩到一维数组。

```c++
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if (grid.empty()) {
            return 0;
        }

        int row = grid.size();      // 行
        int col = grid[0].size();   // 列

        // dp[j] 示从 [i][j] 到 [row - 1][col - 1] 最小路径和。
        vector<int> dp(row);
        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                if (i == row - 1 && j == col - 1) { // 起点
                    dp[j] = grid[i][j];
                } else if (i == row - 1) { // 最后一行
                    dp[j] = dp[j + 1] + grid[i][j];
                } else if (j == col - 1) { // 最后一列
                    dp[j] = dp[j] + grid[i][j];
                } else {
                    dp[j] = min(dp[j], dp[j + 1]) + grid[i][j];
                }
            }
        }

        return dp[0];
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