# 342-3的幂

## 题目

leetcode：[342-3的幂](https://leetcode-cn.com/problems/power-of-three/)

## 循环

从`1`开始循环乘以`3`，直到乘积大于等于`n`，最后判断乘积是否等于`n`。

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        int m = 1;
        while (m < n) {
            m *= 3;
        }

        return m == n;
    }
};
```

## 整数限制

参考[LeetCode官方题解 方法四](https://leetcode-cn.com/problems/power-of-three/solution/3de-mi-by-leetcode/)和[博客 解法二](https://github.com/grandyang/leetcode/issues/326)。

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
```

## 换底公式

参考[博客 解法三](https://github.com/grandyang/leetcode/issues/326)。

```c++
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (static_cast<int>(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
    }
};
```

## 3进制

参考[LeetCode pkoukk的评论](https://leetcode-cn.com/problems/power-of-three/comments/36225)和[LeetCode官方题解 方法二](https://leetcode-cn.com/problems/power-of-three/solution/3de-mi-by-leetcode/)。

代码：TODO。

