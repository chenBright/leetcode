# 031-下一个排列

## 题目

leetcode：[031-下一个排列](https://leetcode-cn.com/problems/next-permutation/)

## STL

使用STL的`next_permutation`函数。（偷懒）

```c++
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
```

## 参考Leetcode题解

参考[LeetCode 的题解](https://leetcode-cn.com/problems/next-permutation/solution/)。

## O(n^2)

一开始的解决方法将遍历步骤嵌套起来，导致了时间复杂度变成***O(n^2)***。

```c++
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int length = nums.size();
        if (length == 0 || length == 1) {
            return;
        }

        for (int i = length - 2; i >= 0; --i) {
            for (int j = length - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    // 找到第一对数 nums[j] > nums[i]，即升序结构
                    swap(nums[j], nums[i]); // 交换
                    // 对[i + 1 ... length - 1]排序，达到最小
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }

        // 数组降序，改成升序
        reverse(nums.begin(), nums.end());
    }
};
```

## O(n)

其实查找i，j的过程可以展平，不需要嵌套在一起。这样处理，时间复杂度变成***O(n)***。

```c++
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int length = nums.size();
        if (length == 0 || length == 1) {
            return;
        }

        int i = length - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        // 此时序列为最大，直接翻转整个数组。
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 找到第一对数 nums[j] > nums[i]，即升序结构
        int j = length - 1;
        while (nums[j] <= nums[i]) {
            --j;
        }
        swap(nums[i], nums[j]);

        // 对区域 [i + 1, length - 1] 排序，达到序列最小
        sort(nums.begin() + i + 1, nums.end());
    }
};
```

