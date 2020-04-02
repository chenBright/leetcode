# 162-寻找峰值

## 题目

leetcode：[162-寻找峰值](https://leetcode-cn.com/problems/find-peak-element/)

## 二分查找

- 规律一：如果`nums[i] > nums[i+1]`，则在`i`之前一定存在峰值元素

- 规律二：如果`nums[i] < nums[i+1]`，则在`i+1`之后一定存在峰值元素

二分查找的时间复杂度为**O(logn)**。

### 实现1

```c++
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int length = nums.size();
        if (nums.empty()) {
            return -1;
        } else if (length == 1) {
            return 0;
        }

        int low = 0;
        int high = length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid == 0) {
                if (nums[mid] > nums[mid + 1]) { // 峰值
                    return mid;
                } else {
                    ++low;
                }
            } else if (mid == length - 1) {
                if (nums[mid] > nums[mid - 1]) { // 峰值
                    return mid;
                } else {
                    --high;
                }
            } else {
                if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) { // 峰值
                    return mid;
                } else if (nums[mid - 1] < nums[mid]) { // 峰值在mid右边
                    low = mid + 1;
                } else {  // 峰值在mid左边
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
```

### 实现2

参考[LeetCode评论区 李一一 的实现](https://leetcode-cn.com/problems/find-peak-element/comments/27112)。

因为题目已知肯定存在峰值，所以有非常简洁的解法。

- 当`nums[mid] > nums[mid + 1]`时，则`high = mid`，保证了最后`nums[low] > nums[low + 1]`。
- 否则，`low = mid + 1`，保证了最后`nums[low] > nums[low - 1]`。

最后，`nums[low]`就是峰值。

```c++
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid + 1]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
```

