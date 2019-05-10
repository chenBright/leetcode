# 073-矩阵置零

## 题目

leetcode：[073-矩阵置零](https://leetcode-cn.com/problems/set-matrix-zeroes/)


## 思路

使用两个`set`来分别保存0元素的行号和列号。使用`set`的目的是为了去重。

遍历完数组，保存好行号和列号之后，就将相应的行和列置0.

```c++
class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        set<int> rowSet; // 保存 0 元素的行号
        set<int> colSet; // 保存 0 元素的列号
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rowSet.insert(i);
                    colSet.insert(j);
                }
            }
        }

        // 将相应的行置0
        for (const auto &row : rowSet) {
            for (int m = 0; m < matrix[0].size(); ++m) {
                matrix[row][m] = 0;
            }
        }

        // 将相应的列置0
        for (const auto &row : colSet) {
            for (int n = 0; n < matrix.size(); ++n) {
                matrix[n][row] = 0;
            }
        }
    }
};
```

