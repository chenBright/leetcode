# 041-缺失的第一个正数

## 题目

leetcode：[041-缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)

## 桶排序 + 抽屉原理

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

        for (int j = 0; j < length; ++j) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }

        return length + 1;
    }
};
```
