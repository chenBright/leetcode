# 309-最佳买卖股票时机含冷冻期

## 题目

leetcode：[309-最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

## 股票问题索引

- [121-买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
- [122-买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
- [123-买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
- [188-买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)
- [309-最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
- [714-买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)


## 动态规划

参考[一个方法团灭 6 道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/)

时间复杂度：**O(n)**。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = INT_MIN; // 代表 dp[i][0]，表示当前持有股票
        int dp_1 = 0;       // 代表 dp[i][1]，表示当前没有持有股票
        int dp_pre_1 = 0;   // 代表 dp[i-2][1]，表示上一次卖出股票

        for (const auto& price : prices) {
            // 前一天没有持有股票，当日也没有持有股票，没有操作
            // 前一天持有股票，当日卖出股票
            dp_0 = max(dp_0, dp_pre_1 - price);
            dp_pre_1 = dp_1;
            // 前一天持有股票，当日也持有股票，没有操作
            // 上一次卖出股票，前一天没有操作，当日买入股票
            dp_1 = max(dp_1, dp_0 + price);
        }

        return dp_1;
    }
};
```

## 二维数组

参考[LeetCode题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/309-zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-q/)。

时间复杂度：**O(n)**。
空间复杂度：**O(3n) = O(n)**。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int length = prices.size();
        // dp[i][j]：i 表示第 i + 1 天。
        // j = 0、1、2
        // 0：表示卖出股票
        // 1：表示持有股票
        // 2：表示处于过渡期
        vector<vector<int> > dp(length, vector<int>(3));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for (int i = 1; i < length; ++i) {
            // 前一天买入股票，当日卖出股票
            dp[i][0] = dp[i - 1][1] + prices[i];
            // 前一天买入股票，当日不操作
            // 前一天过渡期，当日买入股票
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i]);
            // 前一天过渡期，当日也是过渡期
            // 前一天卖出股票，当日也是过渡期
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][0]);
        }

        // 最后一天最大值情况为要么什么都不做，要么卖出股票。
        return max(dp[length - 1][0], dp[length - 1][2]);
    }
};
```

### 压缩空间

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0;       // 卖出股票
        int hold = INT_MIN; // 持有股票
        int rest = 0;       // 过渡期
        for (int p : prices) {
            int pre_sold = sold;
            // 前一天 hold，当日卖出股票
            sold = hold + p;
            // 前一天 hold，当日 rest
            // 前一天 rest，当日买入股票变为 hold
            hold = max(hold, rest - p);
            // 前一天 sold，当日必须 rest
            // 前一天 rest，当日继续 rest
            rest = max(rest, pre_sold);
        }

        // 最后一天最大值情况为要么什么都不做，要么卖出股票。
        return max(sold, rest);
    }
};
```
