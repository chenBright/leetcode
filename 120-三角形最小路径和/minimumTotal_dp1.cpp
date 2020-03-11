#include <vector>
using namespace std;

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
