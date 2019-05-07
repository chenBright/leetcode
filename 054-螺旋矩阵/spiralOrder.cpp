#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }

        int row1 = 0;
        int row2 = matrix.size() - 1;
        int col1 = 0;
        int col2 = matrix[0].size() - 1;
        while (row1 <= row2 && col1 <= col2) {
            int i = col1;
            while (i <= col2) {
                res.push_back(matrix[row1][i]);
                ++i;
            }

            i = row1 + 1;
            while (i <= row2) {
                res.push_back(matrix[i][col2]);
                ++i;
            }

            i = col2 - 1;
            while (i >= col1 && row1 != row2) {
                res.push_back(matrix[row2][i]);
                --i;
            }

            i = row2 - 1;
            while (i >= row1 + 1 && col1 != col2) {
                res.push_back(matrix[i][col1]);
                --i;
            }

            ++row1;
            --row2;
            ++col1;
            --col2;
        }

        return res;
    }
};