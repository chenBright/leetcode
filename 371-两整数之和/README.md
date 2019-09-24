# 371-两整数之和

## 题目

leetcode：[371-两整数之和](https://leetcode-cn.com/problems/sum-of-two-integers/)

## 思路

参考[LeetCode题解](https://leetcode-cn.com/problems/sum-of-two-integers/solution/wei-yun-suan-xiang-jie-yi-ji-zai-python-zhong-xu-y/)。

在位运算操作中，**异或**的一个重要特性是**无进位加法**。

假设有两个整数a、b，`a ^ b`得到无进位加的结果，` a & b`得到每一位的进位，让无进位相加的结果与进位不断的异或， 直到进位为0。

### 递归

```c++
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) {
            return a;
        }

        int sum = a ^ b;
        // leetcode 编译器不允许对负数进行左移，即最高位符号位必须要为0，才能左移
        int carry = static_cast<unsigned long>(a & b) << 1;

        return getSum(sum, carry);
    }
};
```

### 迭代

```c++
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // leetcode 编译器不允许对负数进行左移，即最高位符号位必须要为0，才能左移
            int carry = static_cast<unsigned long>(a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};
```

