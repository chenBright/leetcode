# 165-比较版本号

## 题目

leetcode：[165-比较版本号](https://leetcode-cn.com/problems/compare-version-numbers/)

## 使用stoi将对应位置上的版本号转成数字进行比较

使用stoi将对应位置上的版本号转成数字进行比较。如果不相等，则立即返回结果（1或-1）；否则，继续比较下一个位置的版本号。

- 如果字符串遍历结束，且每个位置上的版本号对应相等，则返回0；
- 如果字符串长度不相等，则继续遍历长的字符串，如果出现***非'.'和非'0'***，则表示长的字符串版本号大，返回结果（1或-1）。
- 其他，返回0。

```c++
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        // 题目已经假设字符串不为空，所以可以不做判空（速度提升1倍）
        if (len1 == 0 && len2 == 0) {
            return 0;
        } else if (len1 == 0) {
            return -1;
        } else if (len2 == 0) {
            return 1;
        }

        int i = 0;
        int j = 0;
        // 比较对应位置上的版本号
        while (i < len1 && j < len2) {
            int m = i;
            while (m < len1 && version1[m] != '.') {
                ++m;
            }
            int num1 = stoi(version1.substr(i, m - i));
            i = m + 1;

            int n = j;
            while (n < len2 && version2[n] != '.') {
                ++n;
            }
            int num2 = stoi(version2.substr(j, n - j));
            j = n + 1;

            if (num1 != num2) {
                return num1 > num2 ? 1 : -1;
            }
        }

        if (i >= len1 && j >= len2) { // 两个字符串长度一样
            return 0;
        } else if (i >= len1) { // version2 比 version1 长
            while (j < len2) { // 如果后面的字符中存在 非 '.' 和 非 '0' 的字符，即 '1~9'，则 version2 版本号大，否则，相等
                if (version2[j] != '.' && version2[j] != '0') {
                    return -1;
                }
                ++j;
            }
            return 0;
        } else {
            while (i < len1) {
                if (version1[i] != '.' && version1[i] != '0') { // 同上
                    return 1;
                }
                ++i;
            }
            return 0;
        }
    }
};
```

## 使用istringstream读取版本号上的数字

参考[博客](https://www.cnblogs.com/grandyang/p/4244123.html)。

在字符串后加一个字符`'.'`，使得每个数字后都有一个`'.'`，则每次读一个数字和一个`'.'`。

该实现与前面的不一样，该实现所有比较都在一个循环内完成。如果短的字符串遍历结束，则对应位置上的版本号为`0`（相当于加长了短的字符串，使得与长的字符串达到版本号上的对齐）。

```c++
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream is1(version1 + ".");
        istringstream is2(version2 + ".");
        int num1 = 0;
        int num2 = 0;
        char dot = '.';
        while (is1.good() || is2.good()) {
            if (is1.good()) {
                is1 >> num1 >> dot;
            }
            if (is2.good()) {
                is2 >> num2 >> dot;
            }

            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
            num1 = num2 = 0;
        }

        return 0;
    }
};
```

