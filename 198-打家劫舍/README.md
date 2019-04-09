# 198-打家劫舍

## 题目

leetcode：[198-打家劫舍](https://leetcode-cn.com/problems/house-robber/)

## 动态规划

分三种情况：

1. 数组为空，即没有房间，则返回***0***；
2. 只有一件房间，则返回***nums[0]***。
3. 至少有两件房间，使用***动态规划***。

动态规划：使用***数组dp***记录每间房间的最大收益，***dp[i]***表示 nums[0 …… i] 所能获得最大收益，可能偷第i间（***dp[i - 2] + nums[i]***），也可能不偷，还是按照第***i-1***间的方案偷（***dp[i - 1]***），即***dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])***。最后，***dp的最后一个元素就是最大收益***。

动态规划的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    int rob(vector<int> &nums) {
        int length = nums.size();
        if (nums.empty()) {
            return 0;
        } else if (length == 1) {
            return nums[0];
        }

        /**
         * 至少两件房间
         * dp[i]表示 nums[0 …… i] 所能获得最大收益，可能偷第i间，也可能不偷，还是按照第i-1间的方案偷
         */
        vector<int> dp(length);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < length; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); // 偷第i间 或者 偷第i-1间，不偷第i间
        }

        return dp[length - 1];
    }
};
```

参考[LeetCode评论区 bshyang的实现](https://leetcode-cn.com/problems/house-robber/comments/11090)，这里写了一版很简洁的动态规划解法。

```c++
class Solution {
public:
    int rob(vector<int> &nums) {
        int last = 0;
        int now = 0;
        for (auto num : nums) {
            int tempLast = last;
            last = now;
            now = max(tempLast + num, now);
        }

        return now;
    }
};
```

## 记忆化搜索

参考[LeetCode评论区 Angus-Liu 的记忆化搜索实现](https://leetcode-cn.com/problems/house-robber/comments/3977)。

- 状态：考虑偷***nums[index…num.length)***这个范围内的所有房子。
- 状态转移：***tryRob(n) = Max{rob(0) + tryRob(2), rob(1) + tryRob(3)... rob(n-3) + tryRob(n-1), rob(n-2), rob(n-1)}***。

记忆化搜索的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    int rob(vector<int> &nums) {
        memo.resize(nums.size(), -1);
        return tryRob(nums, 0);
    }

private:
    vector<int> memo;
    int tryRob(vector<int> &nums, int index) {
        int length = nums.size();
        if (index >= length) {
            return 0;
        }

        // 记忆化搜索可以避免重叠子问题的重复运算
        if (memo[index] != -1) {
            return memo[index];
        }

        int res = 0;
        for (int i = index; i < length; ++i) {
            res = max(res, nums[i] + tryRob(nums, i + 2));
        }
        memo[index] = res;

        return res;
    }
};
```

