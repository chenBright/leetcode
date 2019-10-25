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

## 动态规划

动态规划的对象是金额数，***dp[i]***表示金额 i 的最少硬币数。每次取一个硬币，则状态方程为

> ```c++
> dp[i] = min(dp[i], dp[i - coins[j]] + 1);
> ```

时间复杂度：***O(Sn)***，其中***S***为总金额数，***n***为硬币数。

空间复杂度：***O(S)***。

### 自顶向下1

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount, 0);

        return coinChange(coins, amount, count);
    }

private:
    int coinChange(vector<int>& coins, int amount, vector<int>& count) {
        if (amount < 0) {
            return -1;
        } else if (amount == 0) {
            return 0;
        }
        if (count[amount - 1] != 0) {
            return count[amount - 1];
        }

        int minCount = INT_MAX;
        // 动态规划的对象是金额数
        // count[i] 表示金额数为 i 时所需的最少硬币个数
        // F(S) = F(S - C) + 1
        for (const auto& coin : coins) {
            int result = coinChange(coins, amount - coin, count);
            if (result >= 0 && result < minCount) {
                minCount = result + 1;
            }
        }
        count[amount - 1] = minCount == INT_MAX ? -1 : minCount;
        return count[amount - 1];
    }
};
```

###  自顶向下2

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> count;
        count[0] = 0;
        return coinChange(coins, amount, count);
    }

private:
    int coinChange(vector<int>& coins, int amount, unordered_map<int, int>& count) {
        if (amount < 0) {
            return -1;
        }

        if (count.count(amount) != 0) {
            return count[amount];
        }

        int minCount = INT_MAX;
        // 动态规划的对象是金额数
        // count[i] 表示金额数为 i 时所需的最少硬币个数
        // F(S) = F(S - C) + 1
        for (const auto& coin : coins) {
            int result = coinChange(coins, amount - coin, count);
            if (result >= 0) {
                minCount = min(minCount, result + 1);
            }
        }
        count[amount] = minCount == INT_MAX ? -1 : minCount;
        return count[amount];
    }
};
```

### 自底向上

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxCount = amount + 1;
        vector<int> dp(amount + 1, maxCount);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const auto& coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
```

