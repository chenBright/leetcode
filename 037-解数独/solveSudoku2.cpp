#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        helper(board);
    }
private:
    bool helper(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (char c = '1'; c <= '9'; ++c) {
                    if (!isValid(board, i, j, c)) {
                        continue;
                    }
                    board[i][j] = c;
                    if (helper(board)) {
                        return true;
                    }
                    board[i][j] = '.';
                }
                return false;
            }
        }

        return true;
    }

    bool isValid(vector<vector<char> > &board, int i, int j, char value) {
        for (int k = 0; k < 9; ++k) {
            if (board[k][j] != '.' && board[k][j] == value) {
                return false;
            }
            if (board[i][k] != '.' && board[i][k] == value) {
                return false;
            }

            int row = i / 3 * 3 + k / 3;
            int col = j / 3 * 3 + k % 3;
            if (board[row][col] != '.' && board[row][col] == value) {
                return false;
            }
        }

        return true;
    }
};