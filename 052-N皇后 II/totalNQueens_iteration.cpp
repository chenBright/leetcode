#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> queens(n, -1);
        int i = 0;
        while (i >= 0) {
            queens[i] = queens[i] + 1;
            while (i < n && !isValid(queens, i, queens[i])) {
                queens[i] = queens[i] + 1;
            }

            if (queens[i] < n) {
                if (i < n - 1) {
                    ++i;
                    queens[i] = -1;
                } else {
                    ++result;
                }
            } else {
                --i;
            }
        }

        return result;
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