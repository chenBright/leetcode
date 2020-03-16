# 063-不同路径 II

## 题目

leetcode：[063-不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)


## 思路

解法与[062-不同路径](https://leetcode-cn.com/problems/unique-paths/)大致相同，只需要加一个判断，判断当前网格中是否有障碍物。

### 递归

递归实现效率不高，在LeetCode上会"超出时间限制"。

```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = obstacleGrid.size(); // 行
        int m = obstacleGrid[0].size(); // 列

        if (m == 0 && n == 0) {
            return 0;
        }

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        return uniquePaths(0, 0, n - 1, m - 1, obstacleGrid);
    }

private:
    int uniquePaths(int i, int j, int maxI, int maxJ, vector<vector<int> > &obstacleGrid) {
        if (i > maxI || j > maxJ || obstacleGrid[i][j] == 1) { // 已经走出网格的最大范围 或者 有障碍物
            return 0;
        } else if (i == maxI && j == maxJ) { // 已经走到终点
            return 1;
        } else if (i == maxI || j == maxJ) { // 已经做到与终点在同一条边上，只剩一条路可以到达终点
            return 1;
        }

        return uniquePaths(i + 1, j, maxI, maxJ, obstacleGrid) + uniquePaths(i, j + 1, maxI, maxJ, obstacleGrid);
    }
};
```

### 动态规划

判断当前网格中是否有障碍物。

- 如果有，则`dp[i][j] = 0`。
- 如果没有，则`dp[i][j] = dp[i - 1][j] + dp[i][j - 1]`。

时间复杂度：**O(mn)**。
空间复杂度：**O(mn)**。

```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = obstacleGrid.size(); // 行
        int m = obstacleGrid[0].size(); // 列

        if (m == 0 && n == 0) {
            return 0;
        }

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        // dp[i][j]表示从[0][0]到[i][j]存在多少条路径
        vector<vector<long> > dp(n, vector<long>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) { // 有障碍物
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) { // 起点
                    dp[i][j] = 1;
                } else if (i == 0) { // 第一行
                    dp[i][j] = dp[i][j - 1] == 0 ? 0 : 1;
                } else if (j == 0) { // 第一列
                    dp[i][j] = dp[i - 1][j] == 0 ? 0 : 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return static_cast<int>(dp[n - 1][m - 1]);
    }
};
```

