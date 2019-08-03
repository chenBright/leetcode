#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();
        int shorterDim = min(row, col); // 找出最短的边
        for (int i = 0; i < shorterDim; ++i) {
            // 以对角线上的元素为起点，对行和列进行二分查找
            if (search(matrix, target, i, true) || search(matrix, target, i, false)) {
                return true;
            }
        }

        return false;
    }

private:
    // vertical 为 true，表示对列进行搜索，则 index 为列的索引，low、mid、high 为行索引
    // vertical 为 false，表示对行进行搜索，则 index 为行的索引，low、mid、high 为列索引
    bool search(vector<vector<int> > &matrix, int target, int index, bool vertical) {
        int low = index;
        int high = vertical ? matrix.size() - 1 : matrix[0].size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (vertical) { // 对列进行二分查找
                if (matrix[mid][index] == target) {
                    return true;
                } else if (matrix[mid][index] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // 对行进行二分查找
                if (matrix[index][mid] == target) {
                    return true;
                } else if (matrix[index][mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return false;
    }
};
