# 033-搜索旋转排序数组

## 题目

leetcode：[033-搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

## 二分查找

### 方法1

使用[153-寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)的方法找出最小值，将数组分成两个有序数组，最后在两个数组中进行二分查找。

```c++
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int length = nums.size();
        if (length == 0) {
            return -1;
        }

        int low = 0;
        int high = length - 1;
        int mid;
        while (low < high && high - low > 1) {
            int mid = (low + high) / 2;
            // 不是 mid+(-)1，因为 [mid + 1 ... high]可能是有序数组，即 nums[mid + 1] 是最小值
            if (nums[mid] > nums[low]) { // 左半边有序
                low = mid;
            } else { // 右半边有序
                high = mid;
            }
        }

        // 先找到最小值点，将数组分成两个有序数组
        int minIndex = nums[low] < nums[high] ? low : high;
        if (minIndex == 0) {
            return binarySearch(nums, 0, length - 1, target);
        } else {
            int leftIndex = binarySearch(nums, 0, minIndex, target);
            int rightIndex = binarySearch(nums, minIndex, length - 1, target);
            return leftIndex != -1 ? leftIndex : rightIndex;
        }
    }

private:
    int binarySearch(vector<int> &nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
```

### 方法2

- 当`nums[mid] == target`，则查找成功。
- 当`nums[mid] < nums[high]`，表示`(mid, high]`有序：
  - 当`nums[low] <= target < nums[mid]`时，则`high = mid - 1`；
  - 否则，`low = mid + 1`。
- 当`nums[mid] > nums[low]`，表示`[low, mid)`有序:
  - 当`nums[mid] < target <= nums[high]`时，则`low = mid + 1`；
  - 否则，`high = mid - 1`。

```c++
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int midNum = nums[mid];
            int lowNum = nums[low];
            int highNum = nums[high];
            if (midNum == target) {
                return mid;
            }
            if (midNum < highNum) { // 右半边有序
                if (target > midNum && target <= highNum) {
                    // target 在[mid + 1 ... high]之间
                    low = mid + 1;
                } else {
                    // target 在[low ... mid - 1]之间
                    high = mid - 1;
                }
            } else { // 左半边有序
                if (target >= lowNum && target < midNum) {
                    // target 在[low ... mid - 1]之间
                    high = mid - 1;
                } else {
                    // target 在[mid + 1 ... mid]之间
                    low = mid + 1;
                }
            }
        }

        return -1;
    }
};
```
