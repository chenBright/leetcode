# 069-x的平方根

## 题目

leetcode：[069-x的平方根](https://leetcode-cn.com/problems/sqrtx/)


## 暴力破解

i从0开始递增，计算i的平方并与x比较大小，直到i平方大于x为止。此时，`i - 1`位所求值。（注意，如果i是int类型，在某些测试用例下，i平方会溢出。）

```c++
class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) {
            return -1;
        } else if (x == 0) {
            return 0;
        }

        long i = 0;
        while (i * i <= x) {
            ++i;
        }

        return --i;
    }
};
```

## 牛顿迭代法

参考[博客](https://blog.csdn.net/qq_39564672/article/details/88097336)。

```c++
class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) {
            return -1;
        } else if (x == 0) {
            return 0;
        }

        double xk = 1;
        double xk1 = 0;
        double err = 1e-6; // 误差，1e-6就是1乘10的-6次幂
        while (abs(xk - xk1) > err) { // 循环退出的条件是真正解与近似解的误差进入允许的范围
            xk1 = xk;
            xk = (xk + x / xk) / 2; // 迭代公式
        }

        return xk;
    }
};
```

