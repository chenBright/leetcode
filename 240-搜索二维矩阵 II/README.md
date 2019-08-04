# 240-搜索二维矩阵 II

## 题目

leetcode：[240-搜索二维矩阵 II](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/)

## 二分查找

### 逐行（列）二分查找

找出短的边，然后对长边逐行（列）进行二分查找。

时间复杂度：***O(alon(b))***，其中`a = min(n, m), b = max(n, m)`。

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();
        int shorterDim = min(row, col); // 找出最短的边
        bool vertical = shorterDim == col; // 如果最短边为列，则要对列进行二分查找
        // 遍历短边，对长边进行二分查找
        for (int i = 0; i < shorterDim; ++i) {
            if (search(matrix, target, i, vertical)) {
                return true;
            }
        }

        return false;
    }

private:
    // vertical 为 true，表示对列进行搜索，则 index 为列的索引，low、mid、high 为行索引
    // vertical 为 false，表示对行进行搜索，则 index 为行的索引，low、mid、high 为列索引
    bool search(vector<vector<int> > &matrix, int target, int index, bool vertical) {
        int low = 0;
        int high = vertical ? matrix.size() - 1 : matrix[0].size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (vertical) { // 对列进行二分查找
                if (matrix[mid][index] == target) {
                    return true;
                } else if (matrix[mid][index] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // 对行进行二分查找
                if (matrix[index][mid] == target) {
                    return true;
                } else if (matrix[index][mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return false;
    }
};

```

### 以对角线上的元素为起点，对行和列进行二分查找

参考[LeetCode 官方题解解法二](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2)。

时间复杂度：***O(log(n!))***。

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();
        int shorterDim = min(row, col); // 找出最短的边
        for (int i = 0; i < shorterDim; ++i) {
            if (search(matrix, target, i, true) || search(matrix, target, i, false)) {
                return true;
            }
        }

        return false;
    }

private:
    // vertical 为 true，表示对列进行搜索，则 index 为列的索引，low、mid、high 为行索引
    // vertical 为 false，表示对行进行搜索，则 index 为行的索引，low、mid、high 为列索引
    bool search(vector<vector<int> > &matrix, int target, int index, bool vertical) {
        int low = index;
        int high = vertical ? matrix.size() - 1 : matrix[0].size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (vertical) { // 对列进行二分查找
                if (matrix[mid][index] == target) {
                    return true;
                } else if (matrix[mid][index] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // 对行进行二分查找
                if (matrix[index][mid] == target) {
                    return true;
                } else if (matrix[index][mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return false;
    }
};
```

### 对数组分块进行二分查找

参考[LeetCode 官方题解解法三](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2)。

时间复杂度：***O(nlogn)***。

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        return search(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }

private:
    bool search(vector<vector<int> > &matrix, int target, int lowRow, int highRow, int lowCol, int highCol) {
        if (lowRow > highRow || lowCol > highCol) {
            // 区域为空
            return false;
        } else if (target < matrix[lowRow][lowCol] || target > matrix[highRow][highCol]) {
            // target 比数组中最小的数还小或者比最大的数还大
            return false;
        }

        int midCol = (lowCol + highCol) / 2; // 找到中间的列
        int row = lowRow;
        // 查找中间列中第一个比 target 大的数。
        // 此时以 row行、midCol 列为届，将数组为成 4 部分，
        // 其中，左上角部分的数字肯定比 target 小，右下角部分的数字肯定比 target 大。
        // 只有左下角和右上角部分的数字未确定，则递归在这两部分数组中查找。
        while (row <= highRow && matrix[row][midCol] <= target) {
            if (matrix[row][midCol] == target) {
                return true;
            }
            row++;
        }

        return search(matrix, target, row, highRow, lowCol, midCol - 1) 
            || search(matrix, target, lowRow, row - 1, midCol + 1, highCol);
    }
};
```

## 收缩二分查找

参考[LeetCode 官方题解解法四](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2)。

时间复杂度：***O(n + m)***。

### 从左下角开始搜索

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        int i = row - 1;
        int j = 0;
        while (i >= 0 && j < col) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                ++j;
            } else {
                --i;
            }
        }

        return false;
    }
};
```

### 从右上角开始搜索

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        int i = 0;
        int j = col - 1;
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                ++i;
            } else {
                --j;
            }
        }

        return false;
    }
};
```

