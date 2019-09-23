# 052-N皇后 II

## 题目

leetcode：[052-N皇后 II](https://leetcode-cn.com/problems/n-queens-ii/)

## 回溯法

参考[051-N皇后](../051-N皇后/README.md)，只要稍作修改即可。

### 递归

```c++
class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> queens(n, -1);
        solveNQueens(0, queens, result);

        return result;
    }

private:
    void solveNQueens(int currentRow, vector<int> &queens, int &result) {
        int n = queens.size();

        // 满足条件
        if (currentRow == n) {
            ++result;
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
```

### 迭代

```c++
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
```

### 位运算

参考[LeetCode官方题解](https://leetcode-cn.com/problems/n-queens-ii/solution/nhuang-hou-ii-by-leetcode/)。

时间复杂度：***O(n!)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    int totalNQueens(int n) {
        return solveNQueens(0, 0, 0, 0, 0, n);
    }

private:
    /**
     * row: 当前放置皇后的行号
     * hills: 主对角线占据情况 [1 = 被占据，0 = 未被占据]
     * next_row: 下一行被占据的情况 [1 = 被占据，0 = 未被占据]
     * dales: 副对角线占据情况 [1 = 被占据，0 = 未被占据]
     * count: 所有可行解的个数
     */
    int solveNQueens(int row, int hills, int nextRow, int dales, int count, int n) {
        // 棋盘所有的列都可放置，
        // 即，按位表示为 n 个 '1'
        // bin(cols) = 0b1111 (n = 4), bin(cols) = 0b111 (n = 3)
        // [1 = 可放置]
        int colums = (1 << n) - 1;

        if (row == n) {
            ++count;
        } else {
            // 当前行可用的列
            // ! 表示 0 和 1 的含义对于变量 hills, next_row and dales的含义是相反的
            // [1 = 未被占据，0 = 被占据]
            int freeColumns = colums & ~(hills | nextRow | dales);

            // 找到可以放置下一个皇后的列
            while (freeColumns != 0) {
                // 取 free_columns 的第一个为 '1' 的位
                // 在该列我们放置当前皇后
                int currentColumns = -freeColumns & freeColumns;

                // 放置皇后
                // 并且排除对应的列
                freeColumns ^= currentColumns;

                count = solveNQueens(row + 1, 
                                     (hills | currentColumns) << 1, 
                                     nextRow | currentColumns,
                                     (dales | currentColumns) >> 1,
                                     count,
                                     n);
            }
        }

        return count;
    }
};
```

