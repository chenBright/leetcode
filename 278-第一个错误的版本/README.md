# 278-第一个错误的版本

## 题目

leetcode：[278-第一个错误的版本](https://leetcode-cn.com/problems/first-bad-version/)

## 二分查找

时间复杂度：***O(logn)***。

```c++
class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (low < high) {
            // int mid = (low + high) / 2; 有溢出风险
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return high;
    }
};
```

