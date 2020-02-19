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

1. 如果`nums[mid] < nums[0]`，表明数组一定旋转过，且最小值在`[mid, high]`中，则`low = mid`。
2. 否则，`high = mid`。

时间复杂度：**O(logn)**。

```c++
class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }

        // 数组有序
        // 取等于是考虑到数组只有一个元素的情况
        if (nums.front() <= nums.back()) {
            return nums[0];
        }

        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            // 如果是升序数组，nums[mid] 肯定大于 nums[0]。
            // 在旋转数组中，nums[mid] > nums[low]，表示最小值在 [mid, high] 中。
            // 不是 mid+(-)1，因为 [mid + 1 ... high]可能是有序数组，即 nums[mid + 1] 是最小值
            if (nums[mid] < nums.front()) {
                high = mid;
            } else { // 一定旋转过
                low = mid + 1;
            }
        }

        // 此时，low == high
        return nums[high];
    }
};

当然，也可以和`nums[length - 1]`比较。



```c++
class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }

        // 数组有序
        // 取等于是考虑到数组只有一个元素的情况
        if (nums.front() <= nums.back()) {
            return nums[0];
        }

        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            // 无论是在升序数组中，还是在旋转数组中，nums[mid] 肯定大于 nums[0]。
            // 也可以与 nums[length - 1] 比较。
            // 此时，nums[mid] < nums[length - 1]，表示最小值肯定不在在 [mid, high] 中。
            if (nums[mid] < nums.back()) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // 此时，low == high
        return nums[low];
    }
};
```

## 分治

时间复杂度：**O(logn)**。

```c++
class Solution {
public:
    int findMin(vector<int> &nums) {
        return helper(nums, 0, static_cast<int>(nums.size()) - 1);
    }
private:
    // 返回 [low ... high] 范围内的最小值
    int helper(vector<int> &nums, int low, int high) {
        if (low == high) {
            return nums[low];
        }
        if (nums[low] <= nums[high]) {
            return nums[low];
        }

        int mid = low + (high - low) / 2;

        return min(helper(nums, low, mid), helper(nums, mid + 1, high));
    }
};
```

