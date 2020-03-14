# 221-最大正方形

## 题目

leetcode：[221-最大正方形](https://leetcode-cn.com/problems/maximal-square/)

## 动态规划

使用数组`dp`记录最大正方形边长，`dp[i][j]`表示以第 i 行第 j 列为右下角所能构成的最大正方形边长, 则递推式为:`dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j]`, `dp[i][j - 1]`);如果`dp[i - 1][j - 1]`, `dp[i - 1][j]`, dp[i][j - 1]`不相等，合起来就会缺了某个角落，所以只能找最小值。

时间复杂度：**O(nm)**，其中 n、m 分别为矩阵长和宽。

```c++
class Solution {
public:
    int maximalSquare(vector<vector<char> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        // dp[i][j]表示以第i行第j列为右下角所能构成的最大正方形边长, 则递推式为:
        // dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])。
        // dp[i-1][j-1], dp[i-1][j], dp[i][j-1] 不相等，合起来就会缺了某个角落，所以只能找最小值。
        vector<vector<int> > dp(row + 1, vector<int>(col + 1, 0));
        int maxBorder = 0;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col ; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    maxBorder = max(maxBorder, dp[i][j]);
                }
            }
        }

        return maxBorder * maxBorder;
    }
};
```

