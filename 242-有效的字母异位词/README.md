# 242-有效的字母异位词

## 题目

leetcode：[242-有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)

## 思路

对比两个单词出现的字符以及每种字符的个数：

- 如果都相同，则返回true；
- 否则，返回false。

## 使用哈希表记录字符出现的次数

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

### 数组

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int sMap[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++sMap[s[i] - 'a'];
        }

        int tMap[26] = {0};
        for (int j = 0; j < t.size(); ++j) {
            ++tMap[t[j] - 'a'];
        }

        for (int k = 0; k < 26; ++k) {
            if (sMap[k] != tMap[k]) {
                return false;
            }
        }

        return true;

    }
};
```

只需要一个数组的实现：

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int m[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i] - 'a'];
        }

        for (int j = 0; j < t.size(); ++j) {
            if (--m[t[j] - 'a'] < 0) {
                return false;
            }
        }

        return true;

    }
};
```

### hashmap

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i]) == 0) {
                m[s[i]] = 1;
            } else {
                ++m[s[i]];
            }
        }

        for (int j = 0; j < t.size(); ++j) {
            if (m.count(t[j]) == 0 || --m[t[j]] < 0) {
                return false;
            }
        }


        return true;
    }
};
```

## 排序

先对两个数组排序，然后逐个对比他们相应位置上的字符。

- 如果都相同，则返回true；
- 否则，返回false。

时间复杂度：***O(nlogn)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
```

