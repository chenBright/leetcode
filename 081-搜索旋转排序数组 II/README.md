# 081-搜索旋转排序数组 II

## 题目

leetcode：[081-搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)


## 二分查找

与[033-搜索旋转排序数组](../033-搜索旋转排序数组/search2.cpp)类似。

- 当`nums[mid] == target`，则查找成功。
- 当`nums[mid] < nums[high]`，表示`(mid, high]`有序：
  - 当`nums[low] <= target < nums[mid]`时，则`high = mid - 1`；
  - 否则，`low = mid + 1`。

- 当`nums[mid] > nums[low]`，表示`[low, mid)`有序:
  - 当`nums[mid] < target <= nums[high]`时，则`low = mid + 1`；
  - 否则，`high = mid - 1`。

- 当`nums[mid] == nums[high]`，无法判断有序性，则`--high`。例如`[1,3,1,1,1]`，中间值 = 左边值 = 1，左边不是有序。

```c++
class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int midNum = nums[mid];
            int lowNum = nums[low];
            int highNum = nums[high];
            if (target == midNum) {
                return true;
            }

            if (midNum < highNum) { // 右半边有序
                if (midNum <= target && target <= highNum) { // target 在[mid + 1 ... high]之间
                    low = mid + 1;
                } else { // target 在[low ... mid - 1]之间
                    high = mid - 1;
                }
            } else if (midNum > highNum) { // 左半边有序
                if (lowNum <= target && target <= midNum) { // target 在[low ... mid - 1]之间
                    high = mid - 1;
                } else { // target 在[mid + 1 ... mid]之间
                    low = mid + 1;
                }
            } else { // midNum == highNum，无法判断是否有序，例如 [1, 3, 1, 1, 1]
                --high;
            }
        }

        return false;
    }
};
```

