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

### 实现3

在实现2的基础上，先使用`dp`数组记录字符串每个子串是否是回文字符串。

```c++
class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return result;
        }

        int len = s.size();
        // dp[j][i] 表示 s[j..i] 是否为回文字符串
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        for (int i =0; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] ==s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                }
            }
        }

        partitionRecursion(s, 0, dp);

        return result;
    }

private:
    vector<vector<string> > result;
    vector<string> tmpResult;

    void partitionRecursion(string &s, int index, vector<vector<bool> > &dp) {
        int len = s.size();
        if (index >= len) {
            result.push_back(tmpResult);
        }

        for (int i = index; i < len; ++i) {
            if (dp[index][i]) {
                tmpResult.push_back(s.substr(index, i - index + 1));
                partitionRecursion(s, i + 1, dp);
                tmpResult.pop_back();
            }
        }
    }
};
```

### 实现4

在原函数中直接递归。

```c++
class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return {{}}; // 避免返回后，在 for 中无遍历元素，导致结果为空数组
        }

        vector<vector<string> > result;
        for (int i = 0; i < s.size(); ++i) {
            if (!isPalindromic(s, 0, i)) {
                continue;
            }

            for (auto &item : partition(s.substr(i + 1))) {
                item.insert(item.begin(), s.substr(0, i + 1));
                result.push_back(item);
            }
        }

        return result;
    }

private:
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

## 动态规划

### 实现1

使用`dp`数组记录字符串分割组合。

- `dp[i]` 表示 `s[0..i]`的分割组合

- `dp[i+1]={dp[i] + s[i+1], dp[i-1] + s[i..i+1], ... , dp[0] + s[1..i+1], s[0..i+1]}`

```c++
class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return vector<vector<string> >();
        }

        int len = s.size();
        // dp[i] 表示 s[0..i]的分割组合
        // dp[i+1]={dp[i] + s[i+1], dp[i-1] + s[i..i+1], ... , dp[0] + s[1..i+1], s[0..i+1]}
        vector<vector<vector<string> > > dp(len);
        dp[0].push_back(vector<string>(1, string(1, s[0])));
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!isPalindromic(s, j + 1, i)) {
                    continue;
                }
                // 和 dp[i] 组合
                for (const auto &item : dp[j]) {
                        dp[i].push_back(item);
                        dp[i].rbegin()->push_back(s.substr(j + 1, i - j));
                }
            }
            // 如果 s[0..i] 是回文字符串，则整段分割
            if (isPalindromic(s, 0, i)) {
                dp[i].push_back(vector<string>(1, s.substr(0, i + 1)));
            }
        }

        return *(dp.rbegin());
    }

private:
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

### 实现2

在实现2的基础上，使用`palindromicDp`数组记录字符串每个子串是否是回文字符串。

```c++
class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return vector<vector<string> >();
        }

        int len = s.size();
        // dp[i] 表示 s[0..i]的分割组合
        // dp[i+1]={dp[i] + s[i+1], dp[i-1] + s[i..i+1], ... , dp[0] + s[1..i+1], s[0..i+1]}
        vector<vector<vector<string> > > dp(len);
        dp[0].push_back(vector<string>(1, string(1, s[0])));
        // palindromicDp[j][i] 表示 s[j..i] 是否为回文字符串
        vector<vector<bool> > palindromicDp(len, vector<bool>(len, false));
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                // dp[j] + s[j + 1 .. i]
                if (!(s[i] == s[j + 1] && (i - (j + 1) < 2 || palindromicDp[j + 1 + 1][i - 1]))) {
                    continue;
                }
                palindromicDp[j + 1][i] = true;
                // 和 dp[i] 组合
                for (const auto &item : dp[j]) {
                        dp[i].push_back(item);
                        dp[i].rbegin()->push_back(s.substr(j + 1, i - j));
                }
            }
            // 如果 s[0..i] 是回文字符串，则整段分割
            if (s[0] == s[i] && (i - 0 < 2 || palindromicDp[1][i - 1])) {
                dp[i].push_back(vector<string>(1, s.substr(0, i + 1)));
            }
        }

        return *(dp.rbegin());
    }
};
```

### 实现3

在实现2的基础上，修改了`dp`数组的含义：

- `dp[i]` 表示 `s[0..i - 1]`的分割组合
- `dp[0]` 表示空组合，为了能组合子串不分割的情况
- `dp[i+1]={dp[i] + s[i+1], dp[i-1] + s[i..i+1], ... , dp[0] + s[1..i+1]}`

该实现相对于前两种实现的有点在于：不需要单独处理`s[0..i]`不分割的情况，`dp[0] + s[1..i+1]`即为不分割的情况。

```c++
class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return vector<vector<string> >();
        }

        int len = s.size();
    
        // dp[i] 表示 s[0..i]的分割组合
        // dp[0] 表示空组合，为了不需要单独处理 s[0..i] 不分割的情况，dp[0] + s[1..i+1]即为不分割的情况
        // dp[i+1]={dp[i] + s[i+1], dp[i-1] + s[i..i+1], ... , dp[0] + s[1..i+1]}
        vector<vector<vector<string> > > dp(len + 1);
        // palindromicDp[j][i] 表示 s[j..i] 是否为回文字符串
        vector<vector<bool> > palindromicDp(len, vector<bool>(len, false));
        dp[0].push_back({});
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                // 和 dp[i] 组合
                for (const auto &item : dp[j]) {
                    if (s[i] == s[j] && (i - j < 2 || palindromicDp[j + 1][i - 1])) {
                        palindromicDp[j][i] = true; // j <= i

                        dp[i + 1].push_back(item);
                        dp[i + 1].rbegin()->push_back(s.substr(j, i - j + 1));
                    }
                }
            }
        }

        return *(dp.rbegin());
    }
};
```

