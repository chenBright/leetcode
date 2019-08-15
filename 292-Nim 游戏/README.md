# 292-Nim 游戏

## 题目

leetcode：[292-Nim 游戏](https://leetcode-cn.com/problems/nim-game/)

## 思路

参考[LeetCode官方题解](https://leetcode-cn.com/problems/nim-game/solution/nimyou-xi-by-leetcode)。

规律：

- 当我拿完还剩1、2、3个时，必败，故我拿前有4个时必败，
- 只要在我拿前有5、6、7个时，就可以必胜（5个时拿走一个，6拿2，7拿3，使对手转入拿前4个的必败状态），所以我拿前还有8个时必败（使对手转入必胜的拿前5、6、7状态）。
- ...

## 动态规划

递推关系：

- `dp[i] = !dp[i - 1] | !dp[i - 2] | !dp[i - 3], i >= 4`；
- `dp[1] = true, dp[2] = true, dp[3] = true`。

动态规划的方法在LeetCode上会超时。

```c++
class Solution {
public:
    bool canWinNim(int n) {
        // 不用 dp[0]，所以需要 n + 1 个元素
        vector<bool> dp(n + 1, false);
        dp[1] = true;
        dp[2] = true;
        dp[3] = true;

        for (int i = 4; i <= n; ++i) {
            dp[i] = !dp[i - 1] || !dp[i - 2] || !dp[i - 3];
        }

        return dp[n];
    }
};
```

## 数学规律

```c++
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
```

