#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int rowLength = matrix.size(); // 行数
        int colLength = matrix[0].size(); // 列数
        int length = rowLength * colLength; // 元素总数
        // low、high 为将元素排成一行时的索引（一维索引）
        int low = 0;
        int high = length - 1;
        while (low <= high) {
            int midRow, midCol;
            int mid = (low + high) / 2;
            toIndex(mid, colLength, midRow, midCol);
            int midNum = matrix[midRow][midCol];
            if (midNum == target) {
                return true;
            } else if (midNum < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }

private:
    // 将一维索引转换成二维索引
    void toIndex(int n, int rowLength, int& row, int& col) {
        row = n / rowLength;
        col = n - row * rowLength;
    }
};