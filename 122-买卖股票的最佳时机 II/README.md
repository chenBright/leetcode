# 122-买卖股票的最佳时机 II

## 题目

leetcode：[122-买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

## 贪心算法

参考[LeetCode买卖股票的最佳时机 II官方解答](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/)。

贪心算法的时间复杂度为**O(n)**。

### 贪心算法1

贪心策略：在价格曲线的极小值点买入，在价值曲线的极大值点卖出。如图：

![贪心算法1](./greedy1.png)

```c++
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int vally = 0;
        int peak = 0;
        auto it = prices.begin();
        while (it + 1 != prices.end()) {
            // 找到极小值
            while (it + 1 != prices.end() && *it >= *(it + 1)) {
                ++it;
            }
            vally = *it;

            // 找到极大值
            while (it + 1 != prices.end() && *it <= *(it + 1)) {
                ++it;
            }
            peak = *it;

            profit += peak - vally;
        }

        return profit;
    }
};
```

### 贪心算法2

贪心策略：只要第`i`天的价格比第`i+1`天的价格低，则在第`i`天买入，第`i+1`天卖出。同时，可以在第`i`天卖出，又在第`i`天买入(如果价格还在递增，其实相当于没卖，相当于在极大值点卖出，跟`第一种方法`一样)。如图：

![贪心算法2](./greedy2.png)

```c++
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
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

## 注

图片来自[LeetCode](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/)，侵删。