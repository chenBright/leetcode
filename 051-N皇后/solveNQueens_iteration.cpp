#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> queens(n, -1);
        vector<vector<string> > result;
        int i = 0;
        while (i >= 0) {
            queens[i] = queens[i] + 1; // 初始化或者回溯后判断下一列
            while (queens[i] < n && !isValid(queens, i, queens[i])) {
                queens[i] = queens[i] + 1; // 如果当前列不满足情况，则判断下一列
            }

            if (queens[i] < n) { // 列
                if (i < n - 1) { // 行
                    // 找到合适的位置
                    ++i;
                    // 初始化下一行
                    // （因为 queens 数组多次使用，可能在上一个结果中被设置了未为 -1）
                    queens[i] = -1;
                } else {
                    vector<string> queensStr(n, string(n, '.'));
                    for (int i = 0; i < n; ++i) {
                        queensStr[i][queens[i]] = 'Q';
                    }
                    result.push_back(queensStr);
                }
            } else {
                // 找不到合适的位置，最后 queens[i] == n
                --i;
            }
        }

        return result;
    }

private:
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