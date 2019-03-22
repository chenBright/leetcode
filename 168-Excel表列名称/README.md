# 168-Excel表列名称

## 题目

leetcode：[168-Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/)

## 思路

这道题其实就是一道`26进制`转换的题。一般的进制转换是从0开始的，但这道题要求从1开始，所以每次处理前，n都要减一。

```c++
ublic:
    string convertToTitle(int n) {
        if (n <= 0) {
            return "";
        }

        string tempStr;
        const int system = 26;
        while (n > 0) {
            --n; // 因为从1开始
            int temp = n % system;
            tempStr.append(1, 'A' + temp - 1);
            n /= system;
        }

        return string(tempStr.rbegin(), tempStr.rend());
    }
};
```

