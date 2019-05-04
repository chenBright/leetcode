# 034-在排序数组中查找元素的第一个和最后一个位置

## 题目

leetcode：[034-在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

## equal_range

使用STL中的`equal_range`得到一对表示范围的迭代器。

```c++
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) {
            return res;
        }

        auto range = equal_range(nums.begin(), nums.end(), target);
        if (range.first == nums.end() || *(range.first) != target) {
            return res;
        }
        res[0] = range.first - nums.begin();
        res[1] = range.second - nums.begin() - 1;

        return res;
    }
};
```

## 二分查找

```c++
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) {
            return res;
        }
        int low = lowerBound(nums, 0, nums.size() - 1, target);
        int high = upperBound(nums, 0, nums.size() - 1, target);
        res[0] = low;
        res[1] = high;

        return res;
    }

private:
    int lowerBound(vector<int> &nums, int low, int high, int target) {
        if (low < 0 || high >= nums.size()) {
            return -1;
        }

        int lowTemp = low;
        while (low <= high) {
            int mid = (low + high) / 2;
            int num = nums[mid];
            if (num == target) {
                // 左边界上的元素 或 比左边元素大的元素
                if (mid == lowTemp || num > nums[mid - 1]) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else if (num > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }

    int upperBound(vector<int> &nums, int low, int high, int target) {
        if (low < 0 || high >= nums.size()) {
            return -1;
        }
        
        int highTemp = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            int num = nums[mid];
            if (num == target) {
                // 右边界上的元素 或 比右边元素大的元素
                if (mid == highTemp || num < nums[mid + 1]) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            } else if (num > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
};
```

两个方法的时间复杂度都是***O(logn)***。