# 322-零钱兑换

## 题目

leetcode：[322-零钱兑换](https://leetcode-cn.com/problems/coin-change/)

## 回溯法

组合每种硬币（***0 ~ amount / coins[i]***），在所有组合中找出硬币个数最少的组合。

回溯法，有蛮力法的味道，***超时了***。

时间复杂度：***O(S^n)***，其中***S***为总金额数，***n***为递归深度。

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int result = INT_MAX;
        int tmpResult = 0;
        coinChange(coins, 0, amount, tmpResult, result);

        return result == INT_MAX ? result : -1;
    }

private:
    void coinChange(vector<int>& coins, int index, int amount, int& tmpResult, int& result) {
        if (amount == 0) {
            result = min(result, tmpResult);
            return;
        }

        if (index == coins.size()) {
            return;
        }

        for (int i = 0; i <= amount / coins[index]; ++i) {
            tmpResult += i;
            coinChange(coins, index + 1, amount - i * coins[index], tmpResult, result);
            tmpResult -= i;
        }
    }
};
```

