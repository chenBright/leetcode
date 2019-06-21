# 166-分数到小数

## 题目

leetcode：[166-分数到小数](https://leetcode-cn.com/problems/fraction-to-recurring-decimal/)

## 模拟乘法运算

一开始，我将整数部分和小数部分放在一个循环内处理，问题变得很复杂。如果分开处理，则问题变得简单清晰很多。

整数部分需要考虑的问题：

- 负号问题
- 小数点问题

小数部分需要考虑的问题：

- 循环小数。判断循环小数的依据为，当出现了前面出现过的余数，则可以判断该结果为循环小数。

还需要考虑的问题：整型溢出问题，所以要将整型转类型为`long long`。

参考[博客](https://www.cnblogs.com/grandyang/p/4238577.html)和[LeetCode题解的思路](https://leetcode-cn.com/problems/fraction-to-recurring-decimal/solution/python-kuai-su-pan-duan-xun-huan-xiao-shu-by-idotc)。

```c++
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) {
            return "";
        } else if (numerator == 0) {
            return "0";
        }

        int isNegative1 = numerator < 0 ? -1 : 1;
        int isNegative2 = denominator < 0 ? -1 : 1;
        long long n = abs(static_cast<long long>(numerator));
        long long d = abs(static_cast<long long>(denominator));
        long long out = n / d;
        long long remainder = n % d;
        unordered_map<long long, int> m; // 数字 -> 位置
        // 处理整数部分
        string result = to_string(out);
        // 只有一个负数，则结果中有负号
        if (isNegative1 * isNegative2 == -1) {
            result = "-" + result;
        }
        if (remainder == 0) {
            return result;
        }
        result += ".";

        string decimals; // 小数部分
        int position = 0; // 当前数字的位置
        while (remainder != 0) {
            if (m.find(remainder) != m.end()) { // 出现相同的余数，则表示结果为循环小数
                decimals.insert(m[remainder], "(");
                decimals += ")";
                break;
            }

            m[remainder] = position; // 记录该数字出现的位置
            decimals += to_string(remainder * 10 / d);
            remainder = (remainder * 10) % d;
            ++position;
        }

        return result + decimals;
    }
};
```

