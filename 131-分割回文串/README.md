# 131-分割回文串

## 题目

leetcode：[131-分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/)

## 回溯法

### 实现1

```c++
class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return result;
        }

        partitionRecursion(s);

        return result;
    }

private:
    vector<vector<string> > result;
    vector<string> tmpResult;

    void partitionRecursion(string s) {
        if (s.empty()) {
            result.push_back(tmpResult);
        }

        for (int i = 0; i < s.size(); ++i) {
            string tmp = s.substr(0, i + 1);
            if (isPalindromic(tmp)) {
                tmpResult.push_back(tmp);
                partitionRecursion(s.substr(i + 1));
                tmpResult.pop_back();
            }
        }
    }

    // s是否为回文字符串
    bool isPalindromic(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            ++i;
            --j;
        }

        return true;
    }
};
```

### 实现2

实现1中存在大量的字符串拷贝，运行效率不高。该实现使用索引值来标识子串，从而避免了字符串拷贝，加快了运行速度。

```c++
class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return result;
        }

        partitionRecursion(s, 0);

        return result;
    }

private:
    vector<vector<string> > result;
    vector<string> tmpResult;

    void partitionRecursion(string &s, int index) {
        int len = s.size();
        if (index >= len) {
            result.push_back(tmpResult);
        }

        for (int i = index; i < len; ++i) {
            if (isPalindromic(s, index, i)) {
                tmpResult.push_back(s.substr(index, i - index + 1));
                partitionRecursion(s, i + 1);
                tmpResult.pop_back();
            }
        }
    }
    // s[start …… end]是否为回文字符串
    bool isPalindromic(string &s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }

        return true;
    }
};
```

