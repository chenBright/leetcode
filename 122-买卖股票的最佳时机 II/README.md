# 122-买卖股票的最佳时机 II

## 题目

leetcode：[122-买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

## 股票问题索引

- [121-买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
- [122-买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
- [123-买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
- [188-买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)
- [309-最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
- [714-买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

## 贪心算法

参考[LeetCode买卖股票的最佳时机 II官方解答](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/)。

时间复杂度为**O(n)**。

### 贪心算法1

贪心策略：在价格曲线的极小值点买入，在价值曲线的极大值点卖出。如图：

![贪心算法1](./greedy1.png)

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT_MAX;
        int length = prices.size();
        for (int i = 0; i + 1 < length; ++i) {
            // 找到极小值
            while (i + 1 < length && prices[i] >= prices[i + 1]) {
                ++i;
            }
            if (i >= length) {
                break;
            }
            minPrice = prices[i];
            ++i;

            // 找到极大值
            while (i + 1 < length && prices[i] <= prices[i + 1]) {
                ++i;
            }
            if (i >= length) {
                break;
            }

            profit += prices[i] - minPrice;
        }

        return profit;
    }
};
```

### 贪心算法2

贪心策略：只要第`i`天的价格比第`i+1`天的价格低，则在第`i`天买入，第`i+1`天卖出。同时，可以在第`i`天卖出，又在第`i`天买入(如果价格还在递增，其实相当于没卖，相当于在极大值点卖出，跟`第一种方法`一样)。如图（图片来自[LeetCode](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/)，侵删）：

![贪心算法2](./greedy2.png)

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i + 1 < prices.size(); ++i) {
            int diff = prices[i + 1] - prices[i];
            if (diff > 0) {
                profit += diff;
            }
        }

        return profit;
    }
};
```

## 动态规划

参考[一个方法团灭 6 道股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/)

使用`dp_0`表示持有股票的最大利润，`dp_1`表示未持有股票的最大利润。

在第`i`天，

- 持有股票：
  - 第`i-1`持有股票，第`i`天继续持有股票；
  - 第`i-1`天未持有股票，第`i`天买入股票。
- 未持有股票：
  - 第`i-1`未持有股票，第`i`天继续未持有股票；
  - 第`i-1`天持有股票，第`i`天卖出股票。

```c++
dp_0 = max(dp_0, dp_1 - price);
dp_1 = max(dp_1, dp_0 + price);
```

仔细观察，看到`dp_1 = max(dp_1, dp_0 + price)`会疑惑。`dp_0`表示的不一定是第`i-1`天的结果，可以是第`i`天买入股票的结果。如果此时，`dp_0 + price > dp_1`，则`dp_1 = dp_0 + price`，表示第`i`天先买入股票，再卖出股票，不符合题目要求。

其实这种情况并不会发生。

- 假设`dp_0 >= dp_1 - price`，则`dp_0`不变，第`i`天继续未持有股票。那么对于`dp_1`，无论那种情况都符合要求。
- 假设`dp_0 < dp_1 - price`，则`dp_0 = dp_1 - price`，第`i`天继续买入股票。那么`dp_1 = max(dp_1, dp_0 + price) = max(dp_1, dp_1 -price + price) = max(dp_1, dp_1) = dp_1`，即第`i`天是不会卖出股票的。

所以，不需要在处理`dp_0`前保存`dp_0`。

时间复杂度为**O(n)**。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = INT_MIN; // 持有股票的最大利润
        int dp_1 = 0;       // 没持有股票的最大利润
        for (const auto& price : prices) {
            dp_0 = max(dp_0, dp_1 - price);
            dp_1 = max(dp_1, dp_0 + price);
        }

        return dp_1;
    }
};
```