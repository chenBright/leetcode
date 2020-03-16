#include <vector>
using namespace std;

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