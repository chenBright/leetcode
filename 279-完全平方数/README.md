# 279-完全平方数

## 题目

leetcode：[279-完全平方数](https://leetcode-cn.com/problems/perfect-squares/)

## 深度优先搜索

[参考 LeetCode 评论区 一行 的实现](https://leetcode-cn.com/problems/perfect-squares/comments/53426)。

从大的平方数开始找，每次都尽量多取平方数（贪心策略），直到 n 能将平方数整除。最后，在所有的结果中去最小值。

```c++
class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }

        int minCount = INT_MAX;
        int sq = sqrt(n);
        helper(n, sq, minCount, 0);

        return minCount;
    }

private:
    void helper(int n, int sq, int& minCount, int count) {
        int c = n / (sq * sq);
        if (n % (sq * sq) == 0) {
            // 如果整除，肯定是当前这种分配方式的最小值。
            minCount = min(minCount, count + c);
        } else {
            // 如果当前数字尽量多取，总个数已经超过 minCount，则即使少取该数字，总个数也会超过 minCount（剪枝）。
            for (int i = c; i >= 0 && count + i < minCount; --i) {
                helper(n - i * sq * sq, sq - 1, minCount, count + i);
            }
        }
    }
};
```

## 广度优先搜索（层序遍历）

[参考 LeetCode 评论区 xulong3370 的实现](https://leetcode-cn.com/problems/perfect-squares/comments/6717)。

可以"构建"一个有向图，图结点的值为**总和**，被指向的结点的的值为**总和 - 不大于总和的平方数**。使用广度优先搜索，第一个达到**0结点**的路径长度即为结果。

```c++
class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }

        // <总数, 个数>
        queue<pair<int, int> > q;
        q.push(make_pair(n, 0));

        // 层序遍历减枝，图可能会反复遍历相同的节点。这里之前遍历过的，后面就不用遍历计算了。
        vector<bool> visited(n + 1, false);
        visited[n] = true;

        while (!q.empty()) {
            int num = q.front().first;
            int count = q.front().second;
            q.pop();
            // 搜索与 num 结点相连的结点，
            // 其中边的权值为不大于完全 num 的平方数，结点为 num - 平方数
            for (int i = 1; i * i <= num; ++i) {
                int sub = num - i * i;
                if (sub < 0) {
                    break;
                } else if (sub == 0) {
                    return count + 1;
                } else {
                    if (!visited[sub]) {
                        q.push(make_pair(sub, count + i));
                        visited[sub] = true;
                    }
                }
            }
        }

        return 0;
    }
};
```

## 动态规划

[参考 LeetCode 评论区 Liture 的实现](https://leetcode-cn.com/problems/perfect-squares/comments/61434)。

使用数组`dp`记录最少平方和，`dp[i]`表示成`i`需要的最少平方和，则`dp[n] = 1 + min{ dp[n-1^2], dp[n-2^2], dp[n-3^2], dp[n-4^2], ... , dp[n-k^2] }`，其中`k`为满足`k^2 <= n`的最大的`k`，其中 1 实则为`k^2`的个数。

动态规划的时间复杂度为**O(nlogn)**。

```c++
class Solution {
public:
    int numSquares(int n) {
        /**
         * dp[i]表示凑成 i 需要的最少平方和
         * dp(n) = 1 + min{ dp(n-1^2), dp(n-2^2), dp(n-3^2), dp(n-4^2), ... , dp(n-k^2) }，
         * 其中 k 为满足 k^2 <= n 的最大的 k
         * 其中 1 实则为 k^2 的个数
         */
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int sq = static_cast<int>(sqrt(i));
            int minCount = i;
            for (int j = 1; j <= sq; ++j) {
                minCount = min(minCount, dp[i - j * j]);
            }
            dp[i] = minCount + 1;
        }

        return dp[n];
    }
};
```

## 数学方法

[参考 LeetCode 评论区 fibonacciWH 的实现](https://leetcode-cn.com/problems/perfect-squares/comments/7455)。

**四平方定理**：任何一个正整数都可以表示成不超过四个整数的平方之和。

**推论**：满足四数平方和定理的数 n（四个整数的情况），必定满足*** n = 4^a(8b+7)***。

```c++
class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }

        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }

        int a = 0;
        while (a * a <= n) {
            int b = static_cast<int>(sqrt(n - a * a));
            if (a * a + b * b == n) {
                if (a != 0 && b != 0) {
                    return 2;
                } else {
                    return 1;
                }
            }
            ++a;
        }

        return 3;
    }
};
```

