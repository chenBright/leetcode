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
