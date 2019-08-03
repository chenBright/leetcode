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

        int i = row - 1;
        int j = 0;
        while (i >= 0 && j < col) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                ++j;
            } else {
                --i;
            }
        }

        return false;
    }
};
