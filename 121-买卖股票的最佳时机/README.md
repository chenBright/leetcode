# 121-买卖股票的最佳时机

## 题目

leetcode：[121-买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

## 股票问题索引

- [121-买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)
- [122-买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)
- [123-买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)
- [188-买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)
- [309-最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
- [714-买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

## 蛮力法

蛮力法的时间复杂度为**O(n^2)**。

```c++
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int len = prices.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int diff = prices[j] - prices[i];
                if (diff > profit) {
                    profit = diff;
                }
            }
        }

        return profit;
    }
};
```

## 归并排序(分治)

将数组平均分成两部分，对数组使用归并排序，则最大利润可能出现在：

1. 归并过的数组左半边；
2. 归并过的数组右半边；
3. 整个数组，即`右半边最右边的元素(右半边最大值) - 左半边最左边的元素(左半边最小值) `。

归并排序的时间复杂度为**O(nlogn)**。

```c++
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<int> temp(prices.size());
        int profit = maxProfit(prices, 0, prices.size() - 1, temp);
        if (profit < 0) {
            profit = 0;
        }

        return profit;
    }

private:
    int maxProfit(vector<int> &prices, int low, int high, vector<int> &temp) {
        if (low >= high) {
            return 0;
        }

        int mid = (low + high) / 2;
        int leftProfit = maxProfit(prices, low, mid, temp); // 左半边的最大利润
        int rightProfit = maxProfit(prices, mid + 1, high, temp); // 右半边的最大利润
        // 右半边最大值 - 左半边最小值
        // 因为左右半边的数组都排过序了，
        // 所以左半边的最小值为 prices[low]，右半边的最大值为 prices[high]。
        int holeProfit = prices[high] - prices[low];

        int profit = leftProfit > rightProfit ? leftProfit : rightProfit;
        if (holeProfit > profit) {
            profit = holeProfit;
        }

        int left = low;
        int right = mid + 1;
        int tempIndex = low;
        // 归并排序
        while (left <= mid && right <= high) {
            if (prices[left] <= prices[right]) {
                temp[tempIndex++] = prices[left++];
            } else {
                temp[tempIndex++] = prices[right++];
            }
        }

        while (left <= mid) {
            temp[tempIndex++] = prices[left++];
        }
        while (right <= high) {
            temp[tempIndex++] = prices[right++];
        }

        for (int i = low; i <= high; ++i) {
            prices[i] = temp[i];
        }

        return profit;
    }
};
```

## 动态规划

时间复杂度为**O(n)**。

### 实现1

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
dp_0 = max(dp_0, -price);
dp_1 = max(dp_1, dp_0 + price);
```

仔细观察，看到`dp_1 = max(dp_1, dp_0 + price)`会疑惑。`dp_0`表示的不一定是第`i-1`天的结果，可以是第`i`天买入股票的结果。如果此时，`dp_0 + price > dp_1`，则`dp_1 = dp_0 + price`，表示第`i`天先买入股票，再卖出股票，不符合题目要求。

其实这种情况并不会发生。

- 假设`dp_0 >= -price`，则`dp_0`不变，第`i`天继续未持有股票。那么对于`dp_1`，无论那种情况都符合要求。
- 假设`dp_0 < -price`，则`dp_0 = -price`，第`i`天继续买入股票。因为`dp_1`的初始值为`0`，即`dp_1`恒大于等于`0`，那么`dp_1 = max(dp_1, dp_0 + price) = max(dp_1, -price + price) = max(dp_1, 0) = dp_1`，所以第`i`天是不会卖出股票的。

所以，不需要在处理`dp_0`前保存`dp_0`。

```c++
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int dp_0 = INT_MIN; // 持有股票的最大利润
        int dp_1 = 0;       // 没持有股票的最大利润
        for (const auto& price : prices) {
            dp_0 = max(dp_0, -price);
            dp_1 = max(dp_1, dp_0 + price);
        }

        return dp_1;
    }
};
```

### 实现2

参考[LeetCode买卖股票的最佳时机官方解答](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/)。

前`i`天的最大利润 = `max(前i-1天的最大利润，第i天的价格 - 前i-1天中的最小价格)`。

```c++
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int minPrice = INT_MAX; // 最小价格
        for (const auto& price : prices) {
            minPrice = min(minPrice, price);
            profit = max(profit, price - minPrice);
        }

        return profit;
    }
};
```