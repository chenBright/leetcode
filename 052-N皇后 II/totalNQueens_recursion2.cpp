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