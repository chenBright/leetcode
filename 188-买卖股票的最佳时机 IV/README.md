# 188-买卖股票的最佳时机 IV

## 题目

leetcode：[188-买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)

## 股票问题索引

- [121-买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
- [122-买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
- [123-买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
- [188-买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)
- [309-最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
- [714-买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)


## 动态规划

参考[一个方法团灭 6 道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/)


使用[123-买卖股票的最佳时机 III](../123-买卖股票的最佳时机%20III)的方法来解决，将两笔买卖的变量扩展成长度为 k 的二维数组，即 123 题中的 k = 2。`deals[i][0]`和`deals[i][1]`分别表示第`i`比交易买入和卖出时各自的最大收益。

```c++
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) {
            return 0;
        }

        int length = prices.size();
        if (k >= length / 2) {
            return maxProfitGreedy(prices);
        }

        vector<vector<int>> dp(k, vector<int>{INT_MIN, 0});
        for (const auto& price : prices) {
            dp[0][0] = max(dp[0][0], -price);
            dp[0][1] = max(dp[0][1], dp[0][0] + price);
            for (int i = 1; i < k; ++i) {
                dp[i][0] = max(dp[i][0], dp[i - 1][1] - price);
                dp[i][1] = max(dp[i][1], dp[i][0] + price);
            }
        }

        return dp[k - 1][1];
    }
private:
    int maxProfitGreedy(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT_MIN;
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) {
                profit += diff;
            }
        }

        return profit;
    }

};
```

