# 085-最大矩形

## 题目

leetcode：[085-最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)

## 动态规划

参考[LeetCode官方题解](https://leetcode-cn.com/problems/maximal-rectangle/solution/zui-da-ju-xing-by-leetcode/)。

### 实现1

```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int maxArea = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        // dp[i][j] 表示第 i 行 从左到右，包含 1 的连续序列的宽度（x ~ j）。
        vector<vector<int> > dp(row, vector<int>(col, 0)); 

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j <col; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;
                    int width = dp[i][j]; // 矩形的宽度

                    for (int k = i; k >= 0; --k) {
                        width = min(width, dp[k][j]); // 找最小的宽度，长度为 i - k + 1
                        maxArea = max(maxArea, width * (i - k + 1));
                    }
                }
            }
        }

        return maxArea;
    }
};
```

### 实现2

```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int maxArea = 0;
        // dp[i] 表示第 i 列，从上到下，包含 1 的连续序列的长度
        vector<int> dp(matrix[0].size());

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            maxArea = max(maxArea, helper(dp));
        }

        return maxArea;
    }

private:
    int helper(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int maxArea = 0;
        int length = heights.size();
        for (int i = 0; i < length; ++i) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                int peek = s.top();
                s.pop();
                // 中间空出来的索引，表示两边都高（i 和 s.top()）
                maxArea = max(maxArea, heights[peek] * (i - s.top() - 1));
            }
            s.push(i);
        }

        // 因为栈顶到栈底，高度递减，所以再从右到左计算
        while(s.top() != -1) {
            int peek = s.top();
            s.pop();
            maxArea = max(maxArea, heights[peek] * (length - s.top() - 1));
        }

        return maxArea;
        
    }
};
```

### 实现3

```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty()) {
            return 0;
        }      

        int row = matrix.size();
        int col = matrix.size();

        vector<int> left(row, 0);       // left[i] 表示能容纳第 i + 1列高度的左边界（索引 + 1）
        vector<int> right(row, col);    // right[i] 表示能容纳第 i + 1列高度的右边界（索引）
        vector<int> height(row, 0);     // height[i] 表示第 i + 1 列的高度

        int maxArea = 0;

        for (int i = 0; i < row; ++i) {
            int currentLeft = 0; // 遇到的最右边的 0 的索引加 1（为了方便计算）
            int currentRight = col; // 遇到的最左边的 0 的索引

            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                } else {
                    height[j] = 0;
                }
            }

            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], currentLeft);
                } else {
                    left[j] = 0;
                    currentLeft = j + 1;
                }

            }

            for (int j = col - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], currentRight);
                } else {
                    right[j] = col;
                    currentRight = j;
                }
            }

            for (int j = 0; j < col; ++j) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }

        return maxArea;
    }
};
```

