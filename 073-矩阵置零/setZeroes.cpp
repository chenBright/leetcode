#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        set<int> rowSet; // 保存 0 元素的行号
        set<int> colSet; // 保存 0 元素的列号
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rowSet.insert(i);
                    colSet.insert(j);
                }
            }
        }

        // 将相应的行置0
        for (const auto &row : rowSet) {
            for (int m = 0; m < matrix[0].size(); ++m) {
                matrix[row][m] = 0;
            }
        }

        // 将相应的列置0
        for (const auto &row : colSet) {
            for (int n = 0; n < matrix.size(); ++n) {
                matrix[n][row] = 0;
            }
        }
    }
};