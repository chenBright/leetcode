# 172-阶乘后的零

## 题目

leetcode：[172-阶乘后的零](https://leetcode-cn.com/problems/factorial-trailing-zeroes/)

## 思路

这道题的核心是`统计5的个数`，参考[C++ 数学 详细推导及推广](https://leetcode-cn.com/problems/factorial-trailing-zeroes/comments/2933)。

该方法的时间复杂度为***O(logn)***。

```c++
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n / 5 != 0) {
            n /= 5;
            count += n;
        }

        return count;
    }
};
```

