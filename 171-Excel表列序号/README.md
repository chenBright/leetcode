# 171-Excel表列序号

## 题目

leetcode：[171-Excel表列序号](https://leetcode-cn.com/problems/excel-sheet-column-number/)

## 思路

这道题与[168-Excel表列名称](https://leetcode-cn.com/problems/excel-sheet-column-title/)的都是`26进制`转换问题，这道题是26进制转10机制。

需要注意：`s[length - 1 - i] - 'A'`是从0开始的，例如`'A' - 'A' = 0`，但题目中A对应的是1，不是0，所以需要***加1***。

```c++
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            res += (s[length - 1 - i] - 'A' + 1) * (int)pow(26, i);
        }

        return res;
    }
};
```

