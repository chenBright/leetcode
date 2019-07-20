# 231-2的幂

## 题目

leetcode：[231-2的幂](https://leetcode-cn.com/problems/power-of-two/)

## 迭代

每次迭代都乘以2，直到大于等于n为止。

时间复杂度为：***O(ln(n))***。

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long tmp = 1;
        while (tmp <= n) {
            if (tmp == n) {
                return tmp;
            }

            tmp *= 2;
        }

        return false;
    }
};
```

## 位操作

如果`n`是`2`的幂，则`n`的二进制的最高位为`1`，其他位为`0`。此时`n - 1`的二进制中对应`n`的最高位的位为`0`，后面的位全为`1`。则`n & (n - 1)`一定等于`0`。

时间复杂度：***O(1)***。

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 如果 n 是 2 的幂，则 n 的二进制的最高位为 1，其他位为 0。
        // 此时，n - 1 的二进制中对应 n 的最高位的位为 0，后面的位全为 1。
        // 则 n & (n - 1) 一定等于 0
        return n > 0 && !(n & (n - 1));
    }
};
```

