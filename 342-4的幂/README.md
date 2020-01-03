# 342-4的幂

## 题目

leetcode：[342-4的幂](https://leetcode-cn.com/problems/power-of-four/)

## 换底公式

参考[326-3的幂 换底公式](../326-3的幂/README.md#换底公式)。

```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (static_cast<int>(log10(num) / log10(4)) - log10(num) / log10(4) == 0);
    }
};
```

## 位运算

参考[LeetCode 李一一 的实现](https://leetcode-cn.com/problems/power-of-four/comments/7075)。

理论上数字4幂的二进制类似于100，10000，1000000，etc...形式。可以有如下结论：

1. 4 的幂一定是 2 的幂。
2. 4 的幂和 2 的幂一样，只会出现一位 1。但是，4 的 1 位总是出现在奇数位。
3. `0x5 = 0101b`可以用来校验奇数位上的 1。

```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        // 0x55555555（八进制） == 1010101010101010101010101010101（二进制）（32位）
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
};
```

## 位运算 + 取余

参考[LeetCode 李一一 的评论](https://leetcode-cn.com/problems/power-of-four/comments/7075)。

但是如果可以用取余操作的话，那直接对`4`取余就行了。

```c++
class Solution {
public:
    bool isPowerOfFour(int num) {
        // 4的次方数，减1之后可以被3整除
        // return num > 0 && !(num & (num - 1)) && num % 3 == 1;
        return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
    }
};
```

