# 852-山脉数组的峰顶索引

## 题目

leetcode：[852-山脉数组的峰顶索引](https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/)

## 二分查找

动态规划的时间复杂度为**O(logn)**。

```c++
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        if (A.empty()) {
            return -1;
        }

        int low = 0;
        int high = A.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] <= A[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
```
