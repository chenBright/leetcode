# 461-汉明距离

## 题目

leetcode：[461-汉明距离](https://leetcode-cn.com/problems/hamming-distance/)

## 思路

看到要求找出两个二进制数的位不同，首先想到的是异或运算。两个数异或，得到的结果中，`bit 1`表示原来的两个数在该位不同，而`bit 0`则表示相同。

第二步，就是计算出结果中`bit 1`的个数。参考[191-位1的个数](../191-位1的个数/README.md)。

## 与运算

```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int bits = x ^ y;
        return hammingWeight(bits);
    }

private:
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

```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int bits = x ^ y;
        return hammingWeight(bits);
    }

private:
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

```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int bits = x ^ y;
        return hammingWeight(bits);
    }

private:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int i = 32;
        while (n) {
            n &= n - 1; // 快速移除最右边的 bit 1
            ++count;
        }

        return count;
    }
};
```

