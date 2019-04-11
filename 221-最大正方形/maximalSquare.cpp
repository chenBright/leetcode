#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].size();
        /**
         * dp[i][j]表示以第i行第j列为右下角所能构成的最大正方形边长, 则递推式为: 
         * dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
         * dp[i-1][j-1], dp[i-1][j], dp[i][j-1] 不相等，合起来就会缺了某个角落，所以只能找最小值
         */
        vector<vector<int> > dp(row + 1, vector<int>(col + 1, 0));
        int maxBorder = 0;
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col ; ++j) {
                if (matrix[i - 1][j - 1] == 1) {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    maxBorder = max(maxBorder, dp[i][j]);
                }
            }
        }

        return maxBorder * maxBorder;
    }
};