#include <vector>
using namespace std;

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
