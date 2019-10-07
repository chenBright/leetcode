# 191-位1的个数

## 题目

leetcode：[191-位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)

## 与运算

受[190-颠倒二进制位解法](../190-颠倒二进制位/)启发，可以通过`n & 1`来获取n的最右边的位。

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int i = 32;
        while (i--) {
            count += n & 1; // 获取n的最右边的位
            n >>= 1; // 删除最右边的位
        }

        return count;
    }
};
```

## 取余

也可以通过***对2取余***，来获取最右边的位。

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int i = 32;
        while (i--) {
            count += n % 2; // 获取n的最右边的位
            n >>= 1; // 删除最右边的位
        }

        return count;
    }
};
```

## 与运算，可快速移除最右边的 bit 1

每次将`n & (n - 1)`，可最右边`bit 1`以及其右边的`bit 0`（如果有的话）。

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= n - 1; // 快速移除最右边的 bit 1
            ++count;
        }

        return count;
    }
};
```

