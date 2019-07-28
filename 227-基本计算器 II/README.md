# 227-基本计算器 II

## 题目

leetcode：[227-基本计算器 II](https://leetcode-cn.com/problems/basic-calculator/)

## 思路

因为乘除的优先级比加减的优先级高，所以先将计算乘除，并将结果压入栈中。同时，在遍历的过程中遇到减号，则将减号后面数字的相反数压入栈中。这样就能统一转换成加法了。

参考[LeetCode 李一一 的评论](https://leetcode-cn.com/problems/basic-calculator-ii/comments/32510)和[博客](https://www.cnblogs.com/grandyang/p/4601208.html)。

```c++
class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int len = s.size();
        char op = '+'; // 运算符
        stack<int> numStack;

        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }

            // 不能与前面的 if 合并
            // i == len - 1 表示遍历完字符串，立即计算最后的运算，因为最后的运算可能是乘法或者除法
            // 如果与前面的 if 合并，则不会处理这种情况
            if ((s[i] < '0' && s[i] != ' ') || i == len - 1) {
                if (op == '+') {
                    numStack.push(num);
                } else if (op == '-') {
                    numStack.push(-num);
                } else if (op == '*' || op == '/') {
                    num = op == '*' ? numStack.top() * num : numStack.top() / num;
                    numStack.pop();
                    numStack.push(num);
                }
                op = s[i]; // 更新运算符
                num = 0;
            }
        }

        int result = 0;
        while (!numStack.empty()) {
            result += numStack.top();
            numStack.pop();
        }

        return result;
    }
};
```

