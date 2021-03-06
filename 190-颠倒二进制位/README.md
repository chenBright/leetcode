# 190-颠倒二进制位

## 题目

leetcode：[190-颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)

## 思路

1. 使用变量`ans`保存答案，ans初始化为0。

2. 将`n`中最右边的位取出，加到`ans`中，然后**n右移一位，删除已经处理的最右边的位**，最后将**ans左移，颠倒已经处理的位**。
3. 步骤2，执行***32次***，就可以达到颠倒二进制位的目的。

```c++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1;
            result += n & 1;
            n >>= 1;
        }

        return result;
    }
};
```

