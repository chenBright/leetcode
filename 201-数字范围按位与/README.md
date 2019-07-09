# 201-数字范围按位与

## 题目

leetcode：[201-数字范围按位与](https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/)

## 直接法

参考[博客 解法四](https://www.cnblogs.com/grandyang/p/4431646.html)。

```c++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (n > m) {
            n &= (n - 1);
        }

        return n;
    } 
};
```

## 移位

### 迭代

参考[博客 解法二](https://www.cnblogs.com/grandyang/p/4431646.html)。

```c++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }

        return m << i;
    } 
};
```

### 递归

参考[博客 解法三](https://www.cnblogs.com/grandyang/p/4431646.html)。

```c++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return n > m ? (rangeBitwiseAnd(m / 2, n / 2) << 1) : m;
    } 
};
```