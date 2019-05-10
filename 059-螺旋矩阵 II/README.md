# 059-螺旋矩阵 II

## 题目

leetcode：[059-螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/comments/)


## 代码

```c++
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        if (matrix.empty()) {
            return matrix;
        }

        int row1 = 0;
        int row2 = matrix.size() - 1;
        int col1 = 0;
        int col2 = matrix[0].size() - 1;
        int count = 1;
        while (row1 <= row2 && col1 <= col2) {
            // 上边
            int i = col1;
            while (i <= col2) {
                matrix[row1][i] = count++;
                ++i;
            }

            // 右边
            i = row1 + 1;
            while (i <= row2) {
                matrix[i][col2] = count++;;
                ++i;
            }

            // 下边
            i = col2 - 1;
            while (i >= col1 && row1 != row2) {
                matrix[row2][i] = count++;;
                --i;
            }

            // 左边
            i = row2 - 1;
            while (i >= row1 + 1 && col1 != col2) {
                matrix[i][col1] = count++;;
                --i;
            }

            ++row1;
            --row2;
            ++col1;
            --col2;
        }

        return matrix;
    }
};
```

