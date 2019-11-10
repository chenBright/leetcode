# 416-分割等和子集

## 题目

leetcode：[416-分割等和子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/)

## 动态规划

参考[LeetCode题解](https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/0-1-bei-bao-wen-ti-xiang-jie-zhen-dui-ben-ti-de-yo/)。

### 二维数组

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int length = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 和为奇数，则直接返回 false
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        vector<vector<bool> > dp(length, vector<bool>(target + 1, false));

        // 第一行，因为数组元素都是整数，所以 i 从 1 开始。
        for (int i = 1; i < target + 1; ++i) {
            if (nums[0] == i) {
                dp[0][i] = true;
            }
        }

        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < target + 1; --j) {
                dp[i][j] = dp[i - 1][j]; // 如果 j < nums[i]，则 不能 选择 nums[i]
                if (j >= nums[i]) {
                    // 不选择 nums[i] 或者选择 nums[i]
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
            }
        }

        return dp[length - 1][target];
    }
};
```

### 一维数组

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int length = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 和为奇数，则直接返回 false
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        // 复用上一行的结果
        vector<bool> dp(target + 1, false);

        // 第一行，因为数组元素都是整数，所以 i 从 1 开始。
        for (int i = 1; i < target + 1; ++i) {
            if (nums[0] == i) {
                dp[i] = true;
                break;
            }
        }

        for (int i = 1; i < length; ++i) {
            for (int j = target; j >= 0 && j >= nums[i]; --j) {
                // 不选择 nums[i]，则直接等于上一行的结果，即 dp[j]
                // 或者选择 nums[i]
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};
```

## 再优化

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int length = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 和为奇数，则直接返回 false
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        // 复用上一行的结果
        vector<bool> dp(target + 1, false);

        // 状态转移方程：dp[i - 1][j] = dp[i - 1][j] or dp[i - 1][j - nums[i]]。
        // 单独 1 个数可以构成子集，根据状态转移方程，当 j == nums[i] 成立的时候，会来看 dp[i - 1][0] 的值。
        // 因此根据语义，dp[0] 应该设置为 True。
        dp[0] = true;

        // 第一行，因为数组元素都是整数，所以 i 从 1 开始。
        for (int i = 1; i < target + 1; ++i) {
            if (nums[0] == i) {
                dp[i] = true;
                break;
            }
        }

        for (int i = 1; i < length; ++i) {
            if (target >= nums[i]) {
                dp[target] = dp[target] || dp[target - nums[i]];
            }

            if (dp[target]) {
                return true;
            }

            // 然后再写倒数第 2 个数，倒数第 3 个数 ...
            for (int j = target - 1; j >= 0 && j >= nums[i]; --j) {
                // 不选择 nums[i]，则直接等于上一行的结果，即 dp[j]
                // 或者选择 nums[i]
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};
```

## bitset

参考[博客](https://github.com/grandyang/leetcode/issues/416)。

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 题目中说了数组的长度、每个数字的大小都不会超过 100，那么最大的和为 10000。
        // 10000 一半就是 5000，前面再加上 0，就是 5001 了。
        bitset<5001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 和为奇数，则直接返回 false
        if (sum % 2 != 0) {
            return false;
        }

        for (const auto& n : nums) {
            bits |= bits << n;
        }

        return bits[sum >> 1];
    }
};
```

