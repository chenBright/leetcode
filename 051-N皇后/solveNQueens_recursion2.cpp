#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> queens(n, -1);
        vector<vector<string> > result;
        solveNQueens(0, queens, result);

        return result;
    }

private:
    void solveNQueens(int currentRow, vector<int> &queens, vector<vector<string> > &result) {
        int n = queens.size();

        // 满足条件
        if (currentRow == n) {
            vector<string> queensStr(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                queensStr[i][queens[i]] = 'Q';
            }
            result.push_back(queensStr);
            return;
        }

        for (int i = 0; i < n; ++i) {
            // 符合条件
            if (isValid(queens, currentRow, i)) {
                queens[currentRow] = i; // 放置“皇后”
                solveNQueens(currentRow + 1, queens, result);
                queens[currentRow] = -1; // 还原
            }
        }
    }

    // 验证是否符合条件
    bool isValid(vector<int> &queens, int row, int col) {
        for (int i = 0; i < row; ++i) {
            // 某一行与当前行在同一列放置了“皇后”，它们在数组中的值相等
            // 当两个点在同一条对角线上，二者的横坐标差的绝对值等于纵坐标差的绝对值
            if (queens[i] == col || abs(i - row) == abs(queens[i] - col)) {
                return false;
            }
        }

        return true;
    }
};