# 153-寻找旋转排序数组中的最小值

## 题目

leetcode：[153-寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

## 蛮力法

遍历数组，找到最小值。

蛮力法的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    int findMin(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return -1;
        }

        // 数组有序
        if (nums[0] <= nums[length - 1]) {
            return nums[0];
        }

        int minNum = nums[0];
        for (int i = 1; i < length; ++i) {
            if (nums[i] < minNum) {
                minNum = nums[i];
            }
        }

        return minNum;
    }
};
```

可以通过数组旋转后的特点找到最小值，即最小值比它前面的元素小。

```c++
class Solution {
public:
    int findMin(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return -1;
        }

        for (int i = 1; i < length; ++i) {
            if (nums[i] < nums[i - 1]) {
                return nums[i];
            }
        }

        return nums[0];
    }
};
```

## 二分查找

1. 如果***nums[mid] < nums[low]***，表明数组一定旋转过，且最小值在***[mid … high]***中，则***low = mid***。
2. 否则，***high = mid***。

当然，也可以和***nums[high]***比较。

二分查找的时间复杂度为***O(logn)***。

```c++
class Solution {
public:
    int findMin(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return -1;
        }

        // 数组有序
        if (nums[0] <= nums[length - 1]) {
            return nums[0];
        }

        int low = 0;
        int high = length - 1;
        int mid;
        while (low < high && high - low > 1) {
            int mid = (low + high) / 2;
            // 不是 mid+(-)1，因为 [mid + 1 ... high]可能是有序数组，即 nums[mid + 1] 是最小值
            if (nums[mid] > nums[low]) {
                low = mid; 
            } else { // 一定旋转过
                high = mid;
            }
        }

        return min(nums[low], nums[high]);
    }
};
```

