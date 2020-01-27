# 121-买卖股票的最佳时机

## 题目

leetcode：[121-买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

## 思路

参考[LeetCode买卖股票的最佳时机官方解答](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/)。

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

前`i`天的最大利润 = max{前`i-1 `天的最大利润，第`i`天的价格 - 前`i-1`天中的最小价格}。

动态规划的时间复杂度为**O(n)**。

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