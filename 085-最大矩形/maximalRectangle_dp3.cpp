#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty()) {
            return 0;
        }      

        int row = matrix.size();
        int col = matrix.size();

        vector<int> left(row, 0);       // left[i] 表示能容纳第 i + 1列高度的左边界（索引 + 1）
        vector<int> right(row, col);    // right[i] 表示能容纳第 i + 1列高度的右边界（索引）
        vector<int> height(row, 0);     // height[i] 表示第 i + 1 列的高度

        int maxArea = 0;

        for (int i = 0; i < row; ++i) {
            int currentLeft = 0; // 遇到的最右边的 0 的索引加 1（为了方便计算）
            int currentRight = col; // 遇到的最左边的 0 的索引

            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                } else {
                    height[j] = 0;
                }
            }

            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], currentLeft);
                } else {
                    left[j] = 0;
                    currentLeft = j + 1;
                }

            }

            for (int j = col - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], currentRight);
                } else {
                    right[j] = col;
                    currentRight = j;
                }
            }

            for (int j = 0; j < col; ++j) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }

        return maxArea;
    }
};