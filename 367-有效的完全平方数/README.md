# 367-有效的完全平方数

## 题目

leetcode：[367-有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/solution/you-xiao-de-wan-quan-ping-fang-shu-by-gpe3dbjds1/)

## 迭代

从`1`开始迭代到`sqrt(num)`，判断是否有平方等于`num`的数。

```c++
class Solution {
public:
    bool isPerfectSquare(int num) {
        // 使用 i * i <= num 判断，会有溢出风险
        for (int i = 1; i <= num / i; ++i) {
            if (i * i == num) {
                return true;
            }
        }
        return false;
    }
};
```

## 二分查找

使用二分查找来查找`1 ~ num`之间是否有平方等于`num`的数。

```c++
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long m = mid * mid;
            if (m == num) {
                return true;
            } else if (m > num) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};
```

## 数学

### 完全平方是一系列奇数之和

```
1 = 1
4 = 1 + 3
9 = 1 + 3 + 5
16 = 1 + 3 + 5 + 7
25 = 1 + 3 + 5 + 7 + 9
36 = 1 + 3 + 5 + 7 + 9 + 11
....
1+3+...+(2n-1) = (2n-1 + 1) n/2 = n* n
```

```c++
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }

        return num == 0;
    }
};
```

### 牛顿迭代法

![img](/Users/chenbright/Desktop/c:c++_workspace/leetcode/367-有效的完全平方数/img.png)

```c++
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }

        long r = num;
        while (r * r > num) {
            r = (r + num / r) / 2;
        }

        return r * r == num;
    }
};
```

