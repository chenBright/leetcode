# 038-报数

## 题目

leetcode：[038-报数](https://leetcode-cn.com/problems/count-and-say/)

## 思路

一开始没看懂题目，后来看了一下讨论才知道题目的意思。

题目的意思是对序列前一个数进行报数，数列第一项1，那第二项就报第一项的有1个1，输出1。第三项就在第二项的基础上报数，第二项是11，第三项就是2个1，输出21。以此类推。

```c++
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) {
            return "";
        }

        string s = "1";
        for (int i = 2; i <= n; ++i) {
            string currentS = "";
            char tempCh;
            int count = 0;
            for (int j = 0; j < s.size(); ++j) {
                if (j == 0) { // 第一个字符
                    tempCh = s[j];
                    count = 1;
                    continue;
                }

                if (tempCh == s[j]) { // 字符相同，计数
                    ++count;
                } else { // 不相同，转换为下一字符串，并统计后面字符
                    currentS += intToString(count, tempCh);
                    tempCh = s[j];
                    count = 1;
                }
            }
            currentS += intToString(count, tempCh); // 结束循环时，没有处理的字符
            s = currentS;
        }

        return s;
    }

private:
    string intToString(int count, char ch) {
        stringstream ss;
        string temp;
        ss << count;
        ss >> temp;
        return temp + ch;
    }
};
```
