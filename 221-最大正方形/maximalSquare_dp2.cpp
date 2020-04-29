#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> dp(col + 1, 0);
        int maxBorder = 0;
        for (int i = 1; i <= row; ++i) {
            int last = dp[0];
            for (int j = 1; j <= col; ++j) {
                int tmp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(dp[j - 1], min(dp[j], last)) + 1;
                    maxBorder = max(maxBorder, dp[j]);
                } else {
                    dp[j] = 0; // 容易漏了置 0
                }
                last = tmp;
            }
        }

        return maxBorder * maxBorder;

    }
};
