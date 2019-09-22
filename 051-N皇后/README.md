# 051-N皇后

## 题目

leetcode：[051-N皇后](https://leetcode-cn.com/problems/n-queens/)

## 回溯法

### 递归实现1

参考[博客 解法一](https://github.com/grandyang/leetcode/issues/51)。

```c++
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
```

### 递归实现2

参考[博客 解法二](https://github.com/grandyang/leetcode/issues/51)。

```c++
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
        int n = queens.size();
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
```

### 迭代

参考[博客](https://www.cnblogs.com/yanlingyin/archive/2011/12/19/2292041.html)。该实现是前面***递归实现2***的迭代版本。

```c++
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

            if (queens[i] < n) {
                if (i < n - 1) {
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
        int n = queens.size();
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
```

