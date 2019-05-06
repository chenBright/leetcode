# 048-旋转图像

## 题目

leetcode：[048-旋转图像](https://leetcode-cn.com/problems/rotate-image/)

## 代码

参考[LeetCode评论区 Kico 的评论](https://leetcode-cn.com/problems/rotate-image/comments/45067)。

```c++
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int abs1 = 0;
        int abs2 = matrix.size() - 1;
        while (abs1 <= abs2) {
            int p1 = abs1;
            int p2 = abs2;
            while (p1 != abs2) {
                int temp = matrix[abs1][p1]; // 左上
                matrix[abs1][p1] = matrix[p2][abs1]; // 左上 = 左下
                matrix[p2][abs1] = matrix[abs2][p2]; // 左下 = 右下
                matrix[abs2][p2] = matrix[p1][abs2]; // 右下 = 右上
                matrix[p1][abs2] = temp; // 右上 = 左上
                ++p1;
                --p2;
            }
            ++abs1;
            --abs2;
        }
    }
};
```

