# 560-和为K的子数组

## 题目

leetcode：[560-和为K的子数组](https://leetcode-cn.com/problems/hamming-distance/)

## 累积和

参考[LeetCode 官方题解](https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode/)。

使用数组`sums`记录累积和，其中`sums[i]`表示从第 1 个元素到第 `i`个元素的累积和，`sums[0] = 0`，则`[start .. end)`的累积和 = `sums[end] - sums[start]`。

时间复杂度：***O(n^2)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        if (nums.empty()) {
            return result;
        }

        int length = nums.size();
        // sums[i] 表示 [1 .. i]（第 i 个元素）的和。
        vector<int> sums(length + 1, 0);
        for (int i = 1; i <= length; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int start = 0; start < length; ++start) {
            for (int end = start + 1; end <= length; ++end) {
                // 计算 [start, end) 的累积和
                if (sums[end] - sums[start] == k) {
                    ++result;
                }
            }
        }

        return result;
    }
};
```

## 哈希表

在“累积和”的方法里，不需要知道`start`的的位置，只需要在已知`end`的情况下，有多少个符合条件的累积和即可。

使用哈希表记录累积和，其中`m[i]`表示从第 1 个元素到第 `i`个元素的累积和。遍历数组，以当前的元素为区间的右边界，在哈希表中查找`sum - k`是否存在哈希表中。如果存在，则以当前元素为区间的右边界有`m[sum - k]`个区间符合条件。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        if (nums.empty()) {
            return result;
        }

        int length = nums.size();
        // sums[i] 表示 [1 .. i]（第 i 个元素）的和。
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        for (int i = 0; i < length; ++i) {
            sum += nums[i];
            if (m.count(sum - k) != 0) {
                result += m[sum - k];
            }
            ++m[sum];
        }

        return result;
    }
};
```

