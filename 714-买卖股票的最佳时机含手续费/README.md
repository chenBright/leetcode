# 714-买卖股票的最佳时机含手续费

## 题目

leetcode：[714-买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

## 股票问题索引

- [121-买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
- [122-买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
- [123-买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
- [188-买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)
- [309-最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
- [714-买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)


## 动态规划

时间复杂度：**O(n)**。

### 二维数组

空间复杂度：**O(n)**。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) {
            return 0;
        }

        int length = prices.size();
        // dp[i] 表示第 i + 1 天，对应 prices[i]
        // 0: 持有股票
        // 1: 不持有股票
        vector<vector<int> > dp(length, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < length; ++i) {
            // 前一天持有股票，当天也持有股票
            // 前一天不持有股票，当天买入股票股票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // 前一天不持有股票，当天也不持有股票
            // 前一天持有股票，当天卖出股票股票
            dp[i][1] = max(dp[i - 1][1], dp[i][0] + prices[i]- fee);
        }

        return dp[length - 1][1];
    }
};
```

### 压缩数组

空间复杂度：**O(1)**。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) {
            return 0;
        }

        int dp_0 = 0;           // 不持有股票
        int dp_1 = -prices[0];  // 持有股票
        for (const auto& p : prices) {
            // 前一天不持有股票，当天也不持有股票
            // 前一天持有股票，当天卖出股票股票
            dp_0 = max(dp_0, dp_1 + p - fee);
            // 前一天持有股票，当天也持有股票
            // 前一天不持有股票，当天买入股票股票
            dp_1 = max(dp_1, dp_0 - p);
        }

        return dp_0;
    }
};
```



