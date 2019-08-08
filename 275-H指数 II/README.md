# 275-H指数 II

## 题目

leetcode：[275-H指数 II](https://leetcode-cn.com/problems/h-index-ii/)

## 二分查找

题目要求将算法优化到对数时间复杂度，这明显就是要求使用二分查找来优化了。但这不是普通的二分查找（查找与目标值相等的元素），该二分查找的条件是***查找最后一个文章数大于等于引用的元素***。

参考[LeetCode Binary Search Summary 二分搜索法小结](https://www.cnblogs.com/grandyang/p/6854825.html)。

时间复杂度：***O(logn)***。

空间复杂度：***O(1)***。

###实现1 

```c++
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int len = citations.size();
        int low = 0;
        int high = len - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int papers = len - mid;
            if (papers == citations[mid]) {
                return papers;
            } else if (papers < citations[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // 结束循环后，low、high 肯定与目标值相邻或者重合。
        // 根据实际情况，决定结果。
        return len - low;
    }
};
```

### 实现2

```c++
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int len = citations.size();
        int low = 0;
        int high = len - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int papers = len - mid;
            // 本来是寻找最后一个符合 papers >= citations[mid] 的元素
            // 改成 papers > citations[mid]，可以理解为：
            // 当前 mid 可能不是最后一个符合条件的元素，所以向后移动一个位置继续查找。
            // 最后，结束循环后，low、high 肯定与目标值相邻或者重合。
            // 根据实际情况，决定结果。
            if (papers > citations[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return len - low;
    }
};
```

