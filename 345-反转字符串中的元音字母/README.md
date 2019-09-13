# 345-反转字符串中的元音字母

## 题目

leetcode：[345-反转字符串中的元音字母](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/)

## 直接判断

```c++
class Solution {
public:
    string reverseVowels(string s) {
        string dict("aAeEiIoOuU");
        int i = 0;
        int j = s.size();
        while (i < j) {
            // 从左边查找元音字母
            while (i < j && isVowel(s[i])) {
                ++i;
            }

            // 从右边查找元音字母
            while (j > i && isVowel(s[j])) {
                --j;
            }

            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }

        return s;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I'  || c == 'O' || c == 'U';
    }
};
```

## hash set

```c++
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> charSet{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0;
        int j = s.size();
        while (i < j) {
            // 从左边查找元音字母
            while (i < j && charSet.find(s[i]) == charSet.end()) {
                ++i;
            }

            // 从右边查找元音字母
            while (j > i && charSet.find(s[j]) == charSet.end()) {
                --j;
            }

            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }

        return s;
    }
};
```

## string

```c++
class Solution {
public:
    string reverseVowels(string s) {
        string dict("aAeEiIoOuU");
        int i = 0;
        int j = s.size();
        while (i < j) {
            // 从左边查找元音字母
            while (i < j && dict.find(s[i]) == string::npos) {
                ++i;
            }

            // 从右边查找元音字母
            while (j > i && dict.find(s[j]) == string::npos) {
                --j;
            }

            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }

        return s;
    }
};
```

