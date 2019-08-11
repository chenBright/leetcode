# 290-单词规律

## 题目

leetcode：[290-单词规律](https://leetcode-cn.com/problems/word-pattern/)

## 思路

思路与[205-同构字符串](https://leetcode-cn.com/problems/isomorphic-strings/)相同。该题的不同之处：

1. 有一个匹配是字符串，所以不能使用数组充当哈希表；
2. 需要分割字符串。

## 使用哈希表记录匹配字符或单词

```c++
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        vector<string> sv;
        split(str, sv, ' ');

        if (pattern.size() != sv.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string word = sv[i];
            if (p2s.count(c) != 0 && s2p.count(word) != 0) {
                if (p2s[c] != word) {
                    return false;
                }
            } else if (p2s.count(c) == 0 && s2p.count(word) == 0) {
                p2s[c] = word;
                s2p[word] = c;
            } else {
                return false;
            }
        }

        return true;
    }
private:
    // 分割字符串
    void split(const string &str, vector<string> &sv, const char delim = ' ') {
        istringstream in(str);
        string tmp;
        while (getline(in, tmp, delim)) {
            sv.push_back(std::move(tmp));
        }
    }
};
```

## 使用哈希表记录匹配的位置（索引 + 1）

```c++
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> p2s;
        unordered_map<string, int> s2p;
        vector<string> sv;
        split(str, sv, ' ');

        if (pattern.size() != sv.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string word = sv[i];
            if (p2s.count(c) != 0 && s2p.count(word) != 0) {
                if (p2s[c] != s2p[word]) {
                    return false;
                }
            } else if (p2s.count(c) == 0 && s2p.count(word) == 0) {
                p2s[c] = i + 1;
                s2p[word] = i + 1;
            } else {
                return false;
            }
        }

        return true;
    }
private:
    // 分割字符串
    void split(const string &str, vector<string> &sv, const char delim = ' ') {
        istringstream in(str);
        string tmp;
        while (getline(in, tmp, delim)) {
            sv.push_back(std::move(tmp));
        }
    }
};
```

## 不需要哈希表

```c++
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> sv;
        split(str, sv, ' ');

        if (pattern.size() != sv.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); ++i) {
            if (find(sv.begin(), sv.end(), sv[i]) - sv.begin() != pattern.find(pattern[i])) {
                return false;
            }
        }

        return true;
    }
private:
    // 分割字符串
    void split(const string &str, vector<string> &sv, const char delim = ' ') {
        istringstream in(str);
        string tmp;
        while (getline(in, tmp, delim)) {
            sv.push_back(std::move(tmp));
        }
    }
};
```

