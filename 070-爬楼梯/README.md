# 070-爬楼梯

## 题目

leetcode：[070-爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)


## 递归

使用递归将不能通过测试，因为有很多重复计算。可以使用一个数组来存储计算结果，避免重复计算。

```c++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n + 1); // 用于存储结果，避免重复计算
        cache[0] = 1;
        cache[1] = 1;

        return climbStairsRe(n, cache);
    }

private:
    int climbStairsRe(int n, vector<int> &cache) {
        if (cache[n] > 0) {
            return cache[n];
        }

        int res = climbStairsRe(n - 1, cache) + climbStairsRe(n - 2, cache);
        cache[n] = res;
        return res;
    }
};
```

## 斐波那契数列

观察前面的递归，发现`f(n) = f(n-1) + f(n-2)`。这符合斐波那契数列的规律。

```c++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n + 1);
        cache[0] = cache[1] = 1;

        for (int i = 2; i <= n; ++i) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }

        return cache[n];
    }
};
```

