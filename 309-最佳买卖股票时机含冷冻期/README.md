# 309-最佳买卖股票时机含冷冻期

## 题目

leetcode：[309-最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

## 动态规划

参考[LeetCode题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/309-zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-q/)。

还有[该题解](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-lab/)总结了股票问题的解决方法。

时间复杂度：***O(n)***。

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0;
        int rest = 0;
        int hold = INT_MIN;
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

