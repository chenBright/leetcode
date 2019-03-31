#include <vector>
using namespace std;

// 动态规划
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