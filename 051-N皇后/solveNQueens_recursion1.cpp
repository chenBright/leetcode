#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<string> queens(n, string(n, '.'));
        vector<vector<string> > result;
        solveNQueens(0, queens, result);

        return result;
    }

private:
    void solveNQueens(int currentRow, vector<string> &queens, vector<vector<string> > &result) {
        int n = queens.size();

        // 满足条件
        if (currentRow == n) {
            result.push_back(queens);
            return;
        }

        for (int i = 0; i < n; ++i) {
            // 符合条件
            if (isValid(queens, currentRow, i)) {
                queens[currentRow][i] = 'Q'; // 放置“皇后”
                solveNQueens(currentRow + 1, queens, result);
                queens[currentRow][i] = '.'; // 还原
            }
        }
    }

    // 验证是否符合条件
    bool isValid(vector<string> &queens, int row, int col) {
        int n = queens.size();
        // 验证列
        for (int i = 0; i < n; ++i) {
            if (queens[i][col] == 'Q') {
                return false;
            }
        }

        // 不需要验证 row 行以下的对角线部分，因为那部分还没有“皇后”，肯定满足条件

        // 验证“主对角线”
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (queens[i][j] == 'Q') {
                return false;
            }
        }

        // 验证“副对角线”
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (queens[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};