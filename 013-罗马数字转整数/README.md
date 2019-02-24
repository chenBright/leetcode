# 013-罗马数字转整数

## 题目

leetcode：[013-罗马数字转整数](https://leetcode-cn.com/problems/roman-to-integer/)


## 代码

该题的关键就是3种特殊情况：

1. 如果当前字符是I，检查下一个字符是不是V或X。如果是，i = i + 2。
2. 如果当前字符是X，检查下一个字符是不是L或C。如果是，i = i + 2。
3. 如果当前字符是C，检查下一个字符是不是D或M。如果是，i = i + 2。

```c++
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case 'I':
                    if (s[i + 1] == 'V') {
                        sum += 4;
                        ++i;
                    } else if (s[i + 1] == 'X') {
                        sum += 9;
                        ++i;
                    } else {
                        sum += 1;
                    }
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'X':
                    if (s[i + 1] == 'L') {
                        sum += 40;
                        ++i;
                    } else if (s[i + 1] == 'C') {
                        sum += 90;
                        ++i;
                    } else {
                        sum += 10;
                    }
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'C':
                    if (s[i + 1] == 'D') {
                        sum += 400;
                        ++i;
                    } else if (s[i + 1] == 'M') {
                        sum += 900;
                        ++i;
                    } else {
                        sum += 100;
                    }
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'M':
                    sum += 1000;
                    break;
            }
        }

        return sum;
    }
};
```

