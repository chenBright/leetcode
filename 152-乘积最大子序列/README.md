# 152-乘积最大子序列

## 题目

leetcode：[152-乘积最大子序列](https://leetcode-cn.com/problems/maximum-product-subarray/)

## 动态规划

动态规划的时间复杂度为***O(n)***。

### 两次遍历

参考[LeetCode评论区的思路](https://leetcode-cn.com/problems/maximum-product-subarray/comments/53445)。

1. 如果负数个数为偶数，则整个数组的各个值相乘为最大值；

2. 如果负数个数为奇数，则从左边开始，乘到最后一个负数停止，有一个“最大值”，从右边也有一个“最大值”，比较，得出最大值；

3. 出现0，可以看成将数组拆分两部分，分别求子数组的最大值。

```c++
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return nums[0];
        }

        int maxProduction = INT_MIN; // 最大乘积

        int product = 1;
        // 从左到右计算
        for (int i = 0; i < len; ++i) {
            product *= nums[i];
            // 如果负数个数为奇数，max 在遍历到最后一个负数及以后的数字，就不再更新
            maxProduction = max(maxProduction, product);
            // 遇到 0，停止连乘，初始化乘积为 1
            if (nums[i] == 0) {
                product = 1;
            }
        }

        product = 1;
        // 从右向左计算
        for (int j = len - 1; j >= 0; --j) {
            product *= nums[j];
            // 同上
            maxProduction = max(maxProduction, product);
            if (nums[j] == 0) {
                product = 1;
            }
        }

        return maxProduction;
    }
};
```

下面的实现使用两个数组来分别记录从左到右计算和从右到左计算的状态，可能比较好理解。但本质上思路与前面的实现是一样的。

```c++
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return nums[0];
        }

        vector<int> leftDp(nums.begin(), nums.end());
        // 将数组逆置，这样就可以和leftDp写在同一个循环中，实现从右到左计算
        vector<int> rightDp(nums.rbegin(), nums.rend());

        for (int i = 1; i < len; ++i) {
            // 前一个数为0，则乘1
            leftDp[i] *= leftDp[i - 1] == 0 ? 1 : leftDp[i - 1]; // 从左到右计算
            rightDp[i] *= rightDp[i - 1] == 0 ? 1 : rightDp[i - 1]; // 从右到左计算
        }

        int maxProduction = INT_MIN;
        for (int j = 0; j < len; ++j) {
            maxProduction = max(leftDp[j], maxProduction);
            maxProduction = max(rightDp[j], maxProduction);
        }

        return maxProduction;
    }
};
```

### 一次遍历

[LeetCode评论区 RebelHero 的思路更巧妙](https://leetcode-cn.com/problems/maximum-product-subarray/comments/9718)。

```c++
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return nums[0];
        }

        int maxProduct = INT_MIN;
        int iMax = 1; // 保存最大值
        int iMin = 1; // 保存最小值
        for (int i = 0; i < len; ++i) {
            /**
             * 如果数组的数是负数，
             * 那么会导致最大的变最小的，最小的变最大的。
             * 因此交换两个的值。
             */
            if (nums[i] < 0) {
                swap(iMax, iMin);
            }
            /**
             *  iMax或iMin为0时，即前一个数为0，
             * iMax * nums[i]不一定是最大值，
             * iMin * nums[i]不一定是最小值。
             */
            iMax = max(iMax * nums[i], nums[i]);
            iMin = min(iMin * nums[i], nums[i]);

            maxProduct = max(maxProduct, iMax);
        }

        return maxProduct;
    }
};
```

