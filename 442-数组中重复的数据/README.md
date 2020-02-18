# 442-数组中重复的数据

## 题目

leetcode：[442-数组中重复的数据](https://leetcode-cn.com/problems/longest-consecutive-sequence/)

## 头排序 + 抽屉原理

参考[041-缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)的方法。

参考[LeetCode题解](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/solution/chou-ti-yuan-li-ji-yu-yi-huo-yun-suan-jiao-huan-li/)

```c++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            // 将 nums[i] 放到索引为 nums[i] - 1 的位置，例如，nums[i] = 1，则将 1 放到 索引为 0 的位置
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int j = 0; j < nums.size(); ++j) {
            // 不在对应桶中的元素为重复的元素
            if (nums[j] != j + 1) {
                result.push_back(nums[j]);
            }
        }

        return result;
    }
};
```
