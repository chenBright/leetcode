#include <vector>
using namespace std;

// 从右上角向左下角查找
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) { 
                return true;
            } else if (matrix[row][col] < target) { // 向下查找
                ++row;
            } else { // 向左查找
                --col;
            }
        }

        return false;
    }
};