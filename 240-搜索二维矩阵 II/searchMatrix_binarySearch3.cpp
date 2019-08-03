#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        return search(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }

private:
    bool search(vector<vector<int> > &matrix, int target, int lowRow, int highRow, int lowCol, int highCol) {
        if (lowRow > highRow || lowCol > highCol) {
            // 区域为空
            return false;
        } else if (target < matrix[lowRow][lowCol] || target > matrix[highRow][highCol]) {
            // target 比数组中最小的数还小或者比最大的数还大
            return false;
        }

        int midCol = (lowCol + highCol) / 2; // 找到中间的列
        int row = lowRow;
        // 查找中间列中第一个比 target 大的数。
        // 此时以 row行、midCol 列为届，将数组为成 4 部分，
        // 其中，左上角部分的数字肯定比 target 小，右下角部分的数字肯定比 target 大。
        // 只有左下角和右上角部分的数字未确定，则递归在这两部分数组中查找。
        while (row <= highRow && matrix[row][midCol] <= target) {
            if (matrix[row][midCol] == target) {
                return true;
            }
            row++;
        }

        return search(matrix, target, row, highRow, lowCol, midCol - 1) 
            || search(matrix, target, lowRow, row - 1, midCol + 1, highCol);
    }
};
