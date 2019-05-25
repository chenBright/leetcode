# 188-买卖股票的最佳时机 IV

## 题目

leetcode：[188-买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)

## 动态规划

参考[LeetCode评论区 SEU.FidGet 的答案](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/comments/10285)。

实际上就是整合和扩展了[122-买卖股票的最佳时机 II](../122-买卖股票的最佳时机%20II/)和 [123-买卖股票的最佳时机III](../123-买卖股票的最佳时机%20III/)的方法。

1. 当k大于等于数组长度一半时, 问题退化为贪心问题此时采用[122-买卖股票的最佳时机 II](../122-买卖股票的最佳时机%20II)的方法。
2. 当k不大于数组长度一半时，可以使用[123-买卖股票的最佳时机 III](../123-买卖股票的最佳时机%20III)的方法来解决，将两笔买卖的变量扩展成长度为k的二维数组即可。

```c++
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) {
            return 0;
        }

        int len = prices.size();
        if (k >= len / 2) {
            return maxProfit_greedy(prices);
        }

        int profit = 0;
        vector<pair<int, int> > deals(k, make_pair(INT_MIN, 0));
        for (int p : prices) {
            deals[0].first = max(deals[0].first, -p);
            deals[0].second = max(deals[0].second, deals[0].first + p);
            for (int i = 1; i < k; ++i) {
                deals[i].first = max(deals[i].first, deals[i - 1].second - p);
                deals[i].second = max(deals[i].second, deals[i].first + p);
            }
        }

        return deals[k - 1].second;
    }

private:
    int maxProfit_greedy(vector<int> &prices) {
        int profit = 0;
        if (prices.empty()) {
            return profit;
        }

        for (auto it = prices.begin(); it + 1 != prices.end(); ++it) {
            int diff = *(it + 1) - *it;
            // 只要第i天的价格比第i+1天的价格低，则在第i天买入，第i+1天卖出
            if (diff > 0) {
                profit += diff;
            }
        }

        return profit;
    }
};
```

