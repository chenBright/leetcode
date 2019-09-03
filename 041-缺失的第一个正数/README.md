# 041-缺失的第一个正数

## 题目

leetcode：[041-缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)

## 桶排序

参考[LeetCode题解](https://leetcode-cn.com/problems/first-missing-positive/solution/tong-pai-xu-python-dai-ma-by-liweiwei1419/)。

```c++
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            // 将 nums[i] 放到索引为 nums[i] - 1 的位置，例如，nums[i] = 1，则将 1 放到 索引为 0 的位置
            while (nums[i] > 0 && nums[i] <= length && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < length; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return length + 1;
    }
};
```

题解中给出一种使用位操作来交换两个变量的值，且不需要额外空间。

```c++
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            // 将 nums[i] 放到索引为 nums[i] - 1 的位置，例如，nums[i] = 1，则将 1 放到 索引为 0 的位置
            while (nums[i] > 0 && nums[i] <= length && nums[nums[i] - 1] != nums[i]) {
                swapByBits(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < length; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return length + 1;
    }
private:
    void swapByBits(int &nums1, int &nums2) {
        if (nums1 == nums2) {
            return;
        }

        nums1 = nums1 ^ nums2;
        nums2 = nums1 ^ nums2;
        nums1 = nums1 ^ nums2;
    }
};
```

