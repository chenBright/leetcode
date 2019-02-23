# 007-整数反转

## 题目

leetcode：[007-整数反转](https://leetcode-cn.com/problems/reverse-integer/)


## 思路
该题的难点在于判断溢出（很容易会忽略这个问题），参考[LeetCode整数反转官方解答](https://leetcode-cn.com/problems/reverse-integer/solution/)。

## 使用栈记录每一位上的数字
```c++
class Solution {
public:
    int reverse(int x) {
        queue<int> tempQ;
        int res = 0;
        
        while (x != 0) {
            int n = x % 10;
            x /= 10;
            tempQ.push(n);
        }

        while (!tempQ.empty()) {
            res = res * 10 + tempQ.front();
            tempQ.pop();
            // 判断溢出
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && tempQ.front() == 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && tempQ.front() == -8)) {
                return 0;
            }
        }

        return res;
    }
};
```

## 无需使用栈

该问题无需使用栈，在求每一位上的数字的过程中，可以计算结果。

```c++
class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while (x != 0) {
            int n = x % 10;
            x /= 10;

            // 判断溢出
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && n == 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && n == -8)) {
                return 0;
            }

            res = res * 10 + n;
        }

        return res;
    }
};
```
