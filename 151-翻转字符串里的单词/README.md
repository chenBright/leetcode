# 151-翻转字符串里的单词

## 题目

leetcode：[151-翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)

## 借助栈实现翻转

从头开始遍历字符串，将单词入栈，遍历完之后，再从栈中出栈并拼接成字符串。

```c++
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return "";
        }

        stack<string> strStack;
        auto start = s.begin();
        auto end = start;
        while (start != s.end()) {
            // 跳过空格
            if (*start == ' ') {
                ++start;
                continue;
            }

            end = start;
            // 遍历单词的字母知道遇到空格
            while (end != s.end() && *end != ' ') {
                ++end;
            }

            // 拷贝单词到栈中
            strStack.push(string(start, end));
            start = end;
        }

        string result = "";
        // 从栈中取出单词，从而实现翻转字符串里的单词
        while (!strStack.empty()) {
            result += strStack.top() + " ";
            strStack.pop();
        }

        return result.substr(0, result.size() - 1);
    }
};
```

## 不需要栈，直接使用头插法拼接字符串

与前面方法一样，但不需要使用栈。每遍历到一个单词便插入到结果字符串前面。

```c++
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return "";
        }

        string result = "";
        auto start = s.rbegin();
        auto end = start;
        while (end != s.rend()) {
            // 跳过空格
            if (*end == ' ') {
                ++end;
                continue;
            }

            start = end;
            // 遍历单词的字母知道遇到空格
            while (start != s.rend() && *start != ' ') {
                ++start;
            }
            // 拷贝单词
            // 需要将反向迭代器转成正向迭代器
            result += string(start.base(), end.base()) + " ";
            end = start;
        }
        // 不返回最后一个空格
        return result.substr(0, result.size() - 1);
    }
};
```

## 原地翻转

先翻转整个字符串，然后遍历字符串，遍历到单词后，翻转单词，并跳过前面的空格，拷贝到前面。

```c++
class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return "";
        }

        reverse(s.begin(), s.end());
        int storeIndex = 0, len = s.size();
        for (int i = 0; i < len; ++i) {
            if (s[i] != ' ') {
                int j = i;
                while (j < len && s[j] != ' ') {
                    ++j;
                }

                if (storeIndex != 0) {
                    s[storeIndex++] = ' ';
                }
                reverse(s.begin() + i, s.begin() + j);
                while (i != j) {
                    s[storeIndex++] = s[i++];
                }
            }
        }

        s.erase(s.begin() + storeIndex, s.end());
        return s;
    }
};
```

## 使用istringstream代替遍历，使用头插法拼接字符串

参考[博客](https://www.cnblogs.com/grandyang/p/4606676.html)。

```c++
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string tmp;
        is >> s; // 从流中获取一个单词
        while (is >> tmp) {
            s = tmp + " " + s;
        }
        
        return (s.empty() || s[0] == ' ') ? "" : s;
    }
};
```

