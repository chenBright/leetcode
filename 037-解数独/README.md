# 037-解数独

## 题目

leetcode：[037-解数独](https://leetcode-cn.com/problems/sudoku-solver/)


## 回溯法

参考[博客](https://github.com/grandyang/leetcode/issues/37)。

### 实现1

```c++
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        helper(board, 0, 0);
    }
private:
    bool helper(vector<vector<char> > &board, int i, int j) {
        if (i == 9) {
            return true;
        }
        if (j >= 9) {
            return helper(board, i + 1, 0);
        }
        if (board[i][j] != '.') {
            return helper(board, i, j + 1);
        }
        for (int c = '1'; c <= '9'; ++c) {
            if (!isValid(board, i, j, c)) {
                continue;
            }
            board[i][j] = c;
            if (helper(board, i, j + 1)) {
                return true;
            }
            board[i][j] = '.';
        }

        return false;
    }

    bool isValid(vector<vector<char> > &board, int i, int j, char value) {
        for (int x = 0; x < 9; ++x) {
            if (board[x][j] == value) {
                return false;
            }
        }
        for (int y = 0; y < 9; ++y) {
            if (board[i][y] == value) {
                return false;
            }
        }

        int row = i - i % 3;
        int col = j - j % 3;
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                if (board[x + row][y + col] == value) {
                    return false;
                }
            }
        }

        return true;
    }
};
```

### 实现2

```c++
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
```

