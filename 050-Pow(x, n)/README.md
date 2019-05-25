# 050-Pow(x, n)

## 题目

leetcode：[050-Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)

## 折半计算

使用折半计算，每次把n缩小一半，直到n最终会缩小到0。

- 如果此时n是偶数，直接把上次递归得到的值算个平方返回即可。
- 如果是奇数，则还需要乘上个x的值。

```c++
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }

        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) { // 如果是奇数个，则还需要多出来的 x
                res *= x;
            }
            x *= x;
        }

        return n < 0 ? 1 / res : res;
    }
};
```

