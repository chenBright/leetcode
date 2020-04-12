# 343-整数拆分

## 题目

leetcode：[343-整数拆分](https://leetcode-cn.com/problems/integer-break/)

## 贪心算法

参考[整数拆分 （贪心，清晰图表解析）](https://leetcode-cn.com/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/)。

大数字都可以被**拆分为多个小因子**，以获取更大的乘积，**只有 22 和 33 不需要拆分**。

1. 当`n<=3`时，按照贪心规则应直接保留原数字，但由于题目要求必须拆分，因此必须拆出一个`1`，即直接返回`n - 1`；
2. 求`n`除以`3`的整数部分`a`和余数部分`b`；
3. 当`b==0`时，直接返回 `3^a`；
4. 当`b==1`时，要将一个`1 + 3`转换为`2+2`，此时返回`3^{a-1} * 2`；
5. 当`b == 2`时，返回`3^a * b`。

```c++
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 1) {
            return -1;
        } else if (n <= 3) {
            return n - 1;
        }

        int a = n / 3;
        int b = n % 3;
        if (b == 0) {
            return pow(3, a);
        } else if (b == 1) {
            return pow(3, a - 1) * 2 * 2;
        } else {
            return pow(3, a) * 2;
        }
    }
};
```
