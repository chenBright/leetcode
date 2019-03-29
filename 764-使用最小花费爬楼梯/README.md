# 764-使用最小花费爬楼梯

## 题目

leetcode：[764-使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/)

## 动态规划

动态规划的时间复杂度为***O(n)***。

### 思路1

使用**数组dp**记录达到每一级阶梯所需要的最小花费。因为可以爬一个阶梯或者爬两个阶梯，所以***dp[i] = cost[i] + min(dp[i - 1], dp[i - 2])***。

```c++
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int length = cost.size();
        if (length == 0) {
            return 0;
        } else if (length == 1) {
            return cost[0];
        }

        /**
         * 至少两级台阶
         * dp[i]表示到达阶梯i所需要的最小花费
         */
        vector<int> dp(length, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < length; ++i) {
            // 爬一个阶梯或者爬两个阶梯到达阶梯i
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // 最后两个阶梯都可以到达楼顶
        return min(dp[length - 1], dp[length - 2]);
    }
};
```

### 思路2

参考[LeetCode评论区horanol的实现](https://leetcode-cn.com/problems/min-cost-climbing-stairs/comments/44611)。

```c++
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int pre1 = 0;
        int pre2 = 0;
        /**
         * cost数组每个数字的含义是，当从台阶i离开时，需要花费cost[i]
         * 注意是离开时才有花费，进入台阶i是不花费的，所以只有一个台阶是花费为0(不走这个台阶)，两个台阶时花费为较小的那个台阶(从较小花费的台阶离开)
         * 因此题目的要求实际上是，跨越数组的所有台阶的最小花费
         * 循环从2开始，截止到cost.size()，使得循环结束后，pre2为跨越最后一个台阶的最小花费
         */
        for (int i = 2; i <= cost.size(); ++i) {
            int cur = min(pre1 + cost[i - 2], pre2 + cost[i - 1]);
            pre1 = pre2;
            pre2 = cur;
        }

        return pre2;
    }
};
```

