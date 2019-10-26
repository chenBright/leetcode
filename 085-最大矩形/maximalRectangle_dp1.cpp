#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int maxArea = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        // dp[i][j] 表示第 i 行 从左到右，包含 1 的连续序列的宽度（x ~ j）。
        vector<vector<int> > dp(row, vector<int>(col, 0)); 

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j <col; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
                    int width = dp[i][j]; // 矩形的宽度

                    for (int k = i; k >= 0; --k) {
                        width = min(width, dp[k][j]); // 找最小的宽度，长度为 i - k + 1
                        maxArea = max(maxArea, width * (i - k + 1));
                    }
                }
            }
        }

        return maxArea;
    }
};