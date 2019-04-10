# 263-丑数

## 题目

leetcode：[263-丑数](https://leetcode-cn.com/problems/ugly-number/)

## 实现

```c++
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }

        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else if (num % 3 == 0) {
                num /= 3;
            } else if (num % 5 == 0) {
                num /= 5;
            } else {
                return false;
            }
        }

        return true;
    }
};
```

