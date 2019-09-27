# 140-单词拆分 II

## 题目

leetcode：[140-单词拆分 II](https://leetcode-cn.com/problems/word-break-ii/)

## 回溯法

时间复杂度：***O(n^3)***。

### 实现1

因为存在大量的重复计算，所以超时了。

```c++
class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        vector<string> words;
        vector<string> result;
        dfs(s, wordDict, words, result);

        return result;
    }
private:
    void dfs(string s, vector<string> &wordDict, vector<string> &words, vector<string> &result) {
        if (s.empty()) {
            string tmpResult;
            for (const auto &word : words) {
                tmpResult += word + " ";
            }
            tmpResult.pop_back(); // 删除最后多余的空格
            result.push_back(tmpResult);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            string tmp = s.substr(0, i + 1);
            if (find(wordDict.begin(), wordDict.end(), tmp) != wordDict.end()) {
                words.push_back(tmp);
                dfs(s.substr(i + 1), wordDict, words, result);
                words.pop_back();
            }
        }
    }
};
```

### 记忆化

从[139-单词拆分](../139-单词拆分/README.md#深度优先搜索)可以看出，即使使用索引来避免字符串的切分，还是会超时。但是使用HashMap缓存计算结果，可以避免大量的重复计算，从而不会超时。

```c++
class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_map<string, vector<string> > memory; // <字符串, 字符串的才分结果数组>
        return dfs(s, wordDict, memory);
    }
private:
    vector<string> dfs(string s, vector<string> &wordDict, unordered_map<string, vector<string> > &memory) {
        if (memory.count(s)) {
            return memory[s];
        }

        if (s.empty()) {
            return {""};
        }

        vector<string> result;
        for (const auto &word : wordDict) {
            int wordSize = word.size();
            string tmp = s.substr(0, wordSize);
            if (tmp != word) {
                continue;
            }
            vector<string> tmpResult = dfs(s.substr(wordSize), wordDict, memory);
            for (const auto &str : tmpResult) {
                result.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        memory[s] = result;

        return result;
    }
};
```

## 动态规划

参考[LeetCode官方题解](https://leetcode-cn.com/problems/word-break-ii/solution/dan-ci-chai-fen-ii-by-leetcode/)。

使用一维数组`dp[length]`记录单词拆分的所有情况，`dp[i]`表示`s[0 ... i - 1]`的拆分情况。

***但是，但是，超时了。***

时间复杂度：***O(n^2)***。

```c++
class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        if (!canWordBreak(s, wordDict)) {
            return vector<string>();
        }

        int length = s.size();
        // dp[i]表示 s[0 ... i - 1] 的拆分情况。
        vector<vector<string>  > dp(length + 1);
        dp[0] = vector<string>(1, "");
        for (int i = 1; i <= length; ++i) { // // 找出所有可能的拆分情况
            for (int j = 0; j < i; ++j) {
                string word(s.substr(j, i - j));
                if (dp[j].size() > 0 && find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                    for (const auto &str : dp[j]) {
                        dp[i].push_back(str + (str.empty() ? "" : " ") + word);
                    }
                }
            }
        }

        return dp[length];
    }
};
```

### 优化

[评论区有人提到](https://leetcode-cn.com/problems/word-break-ii/comments/68180)，使用[139-单词拆分](../139-单词拆分/README.md)的方法判断一下能否拆分。如果能，再拆分就不会超时了。

```c++
class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        if (!canWordBreak(s, wordDict)) {
            return vector<string>();
        }

        int length = s.size();
        // dp[i]表示 s[0 ... i - 1] 的拆分情况。
        vector<vector<string>  > dp(length + 1);
        dp[0] = vector<string>(1, "");
        for (int i = 1; i <= length; ++i) { // // 找出所有可能的拆分情况
            for (int j = 0; j < i; ++j) {
                string word(s.substr(j, i - j));
                if (dp[j].size() > 0 && find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                    for (const auto &str : dp[j]) {
                        dp[i].push_back(str + (str.empty() ? "" : " ") + word);
                    }
                }
            }
        }

        return dp[length];
    }
private:
    // “139-单词拆分”中的代码，用于判断是否能拆分。
    bool canWordBreak(string s, vector<string> &wordDict) {
        int strLen = s.size();
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }
        int maxWordLen = 0;
        for (auto it = wordDict.begin(); it != wordDict.end(); ++it) {
            maxWordLen = max(maxWordLen, static_cast<int>(it->size()));
        }

        vector<bool> dp(strLen + 1, false);
        dp[0] = true;
        for (int i = 0; i <= strLen; ++i) {
            for (int j = max(0, i - maxWordLen); j < i; ++j) {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[strLen];
    }
};
```

