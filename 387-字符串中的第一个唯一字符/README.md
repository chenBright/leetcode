# 387-字符串中的第一个唯一字符

## 题目

leetcode：[387-字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)

## 哈希表

遍历字符串，使用哈希表记录字母出现的次数。

再遍历一次字符串，第一个在哈希表找那个次数等于1的字母，就是所求结果，返回它的索引。如果不存在，则返回-1。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (const auto& c : s) {
            ++m[c];
        }

        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
```

