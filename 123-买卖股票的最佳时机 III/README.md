# 123-买卖股票的最佳时机 III

## 题目

leetcode：[123-买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)

## 股票问题索引

- [121-买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
- [122-买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
- [123-买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
- [188-买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)
- [309-最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
- [714-买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

## 动态规划1

参考[hestyle博客](https://blog.csdn.net/qq_41855420/article/details/87867155)。

因为只能买卖两次，所以可以将数组分成两部分，分别求出左边最大利润和右边最大利润（这样利润不会重叠，即第二笔买入出现在第一笔卖出之前）。使用动态规划的地方：

1. 求出左右两边的分界点。
2. 分别求左右两边最大利润，同[121-买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)。

动态规划的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        if (prices.empty()) {
            return profit;
        }

        int len = prices.size();
        int minPrice = prices[0];           // 当前可买入时的最小价格
        int maxPrice = prices[len - 1];     // 当前可卖出的最小价格
        vector<int> leftMaxProfit(len, 0);  // 到i天的左边最大利润
        vector<int> rightMaxProfit(len, 0); // i天之后右边的最大利润
        // 动态规划 第i天之前的最大收入
        for (int i = 1; i < len; ++i) {
            minPrice = min(minPrice, prices[i]);
            leftMaxProfit[i] = max(leftMaxProfit[i - 1], prices[i] - minPrice);
        }
        // 动态规划 第i天之后的最大收入
        for (int j = len - 2; j >= 0; --j) {
            maxPrice = max(maxPrice, prices[j]);
            rightMaxProfit[j] = max(rightMaxProfit[j + 1], maxPrice - prices[j]);
        }
        // 计算左、右和的最大利润
        for (int k = 0; k < len; ++k) {
            profit = max(leftMaxProfit[k] + rightMaxProfit[k], profit);
        }

        return profit;
    }
};
```

## 动态规划2

参考[一个方法团灭 6 道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/)、[LeetCode中文评论区](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/comments/10208)和[LeetCode英文评论区，](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1).)与[122-买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)的思路一样。

动态规划的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        /**
         * 对于任意一天考虑四个变量:
         * fstBuy: 在该天第一次买入股票可获得的最大收益
         * fstSell: 在该天第一次卖出股票可获得的最大收益
         * secBuy: 在该天第二次买入股票可获得的最大收益
         * secSell: 在该天第二次卖出股票可获得的最大收益
         * 分别对四个变量进行相应的更新, 最后secSell就是最大
         * 收益值(secSell >= fstSell)
         */
        int fstBuy = INT_MIN;
        int fstSell = 0;
        int secBuy =INT_MIN;
        int secSell = 0;
        for(int price : prices) {
            fstBuy = max(fstBuy, -price);
            fstSell = max(fstSell, fstBuy + price);
            secBuy = max(secBuy, fstSell - price);
            secSell = max(secSell, secBuy + price);
        }

        return secSell;
    }
};
```
