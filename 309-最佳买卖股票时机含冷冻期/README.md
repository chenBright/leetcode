# 309-最佳买卖股票时机含冷冻期

## 题目

leetcode：[309-最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

## 动态规划

参考[LeetCode题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-lab/)。

时间复杂度：**O(n)**。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = 0;       // dp[i][0]，表示当前没有持有股票
        int dp_1 = INT_MIN; // 代表 dp[i][1]，表示当前持有股票
        int dp_pre_0 = 0;   // 代表 dp[i-2][0]，表示上一次卖出股票

        for (const auto& p : prices) {
            int tmp = dp_0;
            // 前一天没有持有股票，当日也没有持有股票，没有操作
            // 前一天持有股票，当日卖出股票
            dp_0 = max(dp_0, dp_1 + p);
            // 前一天持有股票，当日也持有股票，没有操作
            // 上一次卖出股票，前一天没有操作，当日买入股票
            dp_1 = max(dp_1, dp_pre_0 - p);
            dp_pre_0 = tmp;
        }

        return dp_0;
    }
};
```

