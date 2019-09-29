# 154-寻找旋转排序数组中的最小值 II

## 题目

leetcode：[154-寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)

## 二分查找

时间复杂度：***O(logn)***。

```c++
class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }

        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                high = mid;
            } else { // nums[mid] == nums[high] 时，无法判断收缩的方向，则 --high 再查找
                --high;
            }
        }
        return nums[high];
    }
};
```

## 分治

时间复杂度：***O(logn)***。

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
        if (nums[low] < nums[high]) {
            return nums[low];
        }

        int mid = low + (high - low) / 2;

        return min(helper(nums, low, mid), helper(nums, mid + 1, high));
    }
};
```

