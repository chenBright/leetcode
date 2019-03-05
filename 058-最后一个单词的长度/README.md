# 058-最后一个单词的长度

## 题目

leetcode：[058-最后一个单词的长度](https://leetcode-cn.com/problems/length-of-last-word/)


## 思路

从后往前遍历字符串，如果字符串以空格结尾，则跳过空格，统计最后一个单词的字母个数，知道遇到空格为止。

该方法的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }

        int i;
        for (i = s.size() - 1; s[i] == ' ' && i >= 0; --i); // 跳过空格

        if (i < 0) { // 全是空格
            return 0;
        }

        int count = 0;
        for (; s[i] != ' ' && i >= 0; --i) {
            ++count;
        }

        return count;
    }
};
```

