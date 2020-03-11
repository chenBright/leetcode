# 120-三角形最小路径和

## 题目

leetcode：[120-三角形最小路径和](https://leetcode-cn.com/problems/triangle/)

## 动态规划

基本思路是：使用数组记录到达每个结点的最小路径和，当达到终点后，就能找出最小路径和。

下面三种动态规划实现的时间复杂度都为**O(n^2)**，其中`n`为三角形的总行数。

### 使用二维数组

从上往下走，记录到达每个结点的最小路径和。最后一行的最小值即为三角形的最小路径和。

数组中每个结点的最小路径和：

- 如果结点是一行中的第一个结点时，和为当前结点值 + 上一行第一个结点的路径和。
- 如果结点是一行中的最后一个结点时，和为当前结点值 + 上一行最后一个结点的路径和。
- 其他，和为当前结点值 + 上一行相邻两结点中较小的路径和。

空间复杂度：**O(n^2)**。

```c++
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) {
            return 0;
        }

        int row = triangle.size();
        // dp[i][j] 表示从顶点到达[i][j]结点的最小路径和
        vector<vector<int> > dp(triangle);
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                // 每一行的第一个结点和最后一个结点，只与一个结点相邻
                if (j == 0) {
                    dp[i][j] += dp[i - 1][j];
                } else if (j == i) {
                    dp[i][j] += dp[i - 1][j - 1];
                } else {
                    dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }

        // 找出数组dp最后一行的最小值，即为最小路径和
        int minTotal = INT_MAX;
        for (int k = 0; k < row; ++k) {
            minTotal = min(minTotal, dp[row - 1][k]);
        }

        return minTotal;
    }
};
```

### 原地修改

从下往上走，原地修改输入数组，用于记录最小路径和。达到顶点的路径和即为三角形的最小路径和。

该实现的空间复杂度为**O(1)**，但会破坏输入的数据。

```c++
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) {
            return 0;
        }

        int row = triangle.size();
        // 原地修改，空间复杂度为O(1)，但会破坏了输入。
        // 从下往上走，找出到达顶点的最小路径和。
        for (int i = row - 2; i >= 0; --i) {
            for (int j = 0; j < i + 1; ++j) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};

```

### 一维数组

从下往上走，找出到达顶点的最小路径和。使用一维数组记录到达该层（需要结合循环才知道到达哪一层）第`i + 1`（i 从 0 开始）个结点的最小路径和。观察实现2（原地修改），计算完本层的最小路径后，下一层的数据已经没有价值，可以直接覆盖，复用`dp`数组，以达到压缩空间的目的。

该实现的空间复杂度为**O(n)**。

```c++
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) {
            return 0;
        }

        int row = triangle.size();
        // 本质上是从下往上走，找出到达顶点的最小路径和。
        // 假设三角形 triangle.size() + 1 层，最后一层结点全为 0。
        // dp[i] 表示到达该层（需要结合循环才知道到达哪一层）第 i + 1 个结点的最小路径和。
        // 每一次都复用 dp 数组，因为计算完本层的最小路径后，下一层的数据已经没有价值，可以直接覆盖。
        vector<int> dp(row + 1, 0);
        for (int i = row - 1; i >= 0; --i) {
            for (int j = 0; j < i + 1; ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};
```

