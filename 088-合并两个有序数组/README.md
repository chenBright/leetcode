# 088-合并两个有序数组

## 题目

leetcode：[088-合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/comments/)

## 排序

排序有两种方法：

1. 插入排序：将`nums2`中的元素插入到`nums1`中合适的位置。时间复杂度为***O(mn)***。
2. 先将`nums2`替代`nums1`后面的`0`，然后使用STL中的`sort`函数对`nums1`进行排序，时间复杂度为***O((m+n)log(m+n))***。

方法2的代码：

```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }

        if (n == 0) {
            return;
        }

        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};
```

## 遍历两个数组

从后往前遍历两个数组，先确定大的元素，并将元素放到`nums1`的后面。时间复杂度为***O(m+n)***。

```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }

        if (n == 0) {
            return;
        }

        int i = m + n - 1;
        int j = m - 1;
        int k = n - 1;
        // 从后往前确定元素
        while (j >= 0 && k >= 0) {
            nums1[i--] = nums1[j] > nums2[k] ? nums1[j--] : nums2[k--];
        }

        // nums2还有元素，将剩下的元素复制到nums1中
        if (j < 0) {
            while (k >= 0) {
                nums1[i--] = nums2[k--];
            }
        }
    }
};
```

