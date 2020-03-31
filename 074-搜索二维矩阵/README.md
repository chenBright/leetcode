# 074-搜索二维矩阵

## 题目

leetcode：[074-搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)


## 二分查找

假设将二维数组的元素排成一排，每个元素都有一个索引（从0开始），即可转化为一位数组的二分查找问题。在需要访问元素的时候，将一维索引转换为二维索引。例如：

```c++
// row 为行索引，row 为列索引，index 为一维索引，colLength 为行长度，即一行有多少个元素
row = index / colLength;
col = index - row * colLength;
```

二分查找的时间复杂度为**O(log(mn))，即O(logm + logn)**。

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int rowLength = matrix.size(); // 行数
        int colLength = matrix[0].size(); // 列数
        int length = rowLength * colLength; // 元素总数
        // low、high 为将元素排成一行时的索引（一维索引）
        int low = 0;
        int high = length - 1;
        while (low <= high) {
            int midRow, midCol;
            int mid = (low + high) / 2;
            toIndex(mid, colLength, midRow, midCol);
            int midNum = matrix[midRow][midCol];
            if (midNum == target) {
                return true;
            } else if (midNum < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }

private:
    // 将一维索引转换成二维索引
    void toIndex(int n, int rowLength, int& row, int& col) {
        row = n / rowLength;
        col = n - row * rowLength;
    }
};
```

## 从右上角向左下角查找

从右上角向左下角查找：

1. 如果`matrix[row][col] == target`，则查找成功。
2. 如果`matrix[row][col] < target，则继续向下查找，即行下移，`++row`。
3. 如果`matrix[row][col] > target，则继续向左查找，即列左移，`--col`。

如果结束都没有查找成功，则查找失败。

该方法的时间复杂度为**O(m+n)**。

也可以从左下角向右上角查找。

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) { // 向下查找
                ++row;
            } else { // 向左查找
                --col;
            }
        }

        return false;
    }
};
```

