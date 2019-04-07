# 139-单词拆分

## 题目

leetcode：[139-单词拆分](https://leetcode-cn.com/problems/word-break/)

## 深度优先搜索

深度优先搜索效率不高，在LeetCode上会"超出时间限制"。

一开始不太懂深度优先搜索在这道题的应用，主要是觉得像图那样才能用深度优先搜索。这里深度优先搜索的思路是：找到匹配的子串后，在除了已匹配的子串外的子串中继续找匹配的子串，直到整个字符串都能找到匹配的子串。

有需要优化的地方：***子串的长度不需要从0开始，只需要是字典中单词的长度即可***。

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int strLen = s.size();
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }

        for (auto word : wordDict) {
            wordLenSet.insert(word.size());
            wordSet.insert(word);
        }

        return dfs(s, 0);
    }

private:
    set<int> wordLenSet; // 用于储存wordDict中单词的长度
    set<string> wordSet; // 记录单词出现次数

    bool dfs(string &s, int start) {
        int strLen = s.size();
        if (start >= strLen) {
            return true;
        }

        for (auto it = wordLenSet.rbegin(); it != wordLenSet.rend(); ++it) { // set默认从大到小排序，先从短子串开始搜索
            string subStr = s.substr(start, *it); // 以start为起始，获取*it长的子串
            if (wordSet.find(subStr) != wordSet.end() && dfs(s, start + *it)) {
                return true;
            }
        }

        return false;
    }
};
```

## 广度优先搜索

广度优先搜索也超时。

广度优先搜索的思路：在某个起点，搜索所有可能的长度（字典中单词的长度）的子串，匹配则将子串最后一个字符下一个位置入队，供下一次搜索。

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int strLen = s.size();
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }

        set<int> wordLengthSet; // 用于储存wordDict中单词的长度
		int strSize = s.size();
		// 首先扫描一遍，获取wordDict长度的种类
		for (auto word : wordDict) {
			wordLengthSet.insert(word.size());
		}
		queue<int> myQueue;
		myQueue.push(0);
		int tempQueueSize, tempBegin;
		while (!myQueue.empty()) {
			tempQueueSize = myQueue.size();
			for (int i = 0; i < tempQueueSize; ++i) {
				tempBegin = myQueue.front();
				myQueue.pop();
				for (auto it = wordLengthSet.rbegin(); it != wordLengthSet.rend(); ++it) { // set默认从大到小排序，先从短子串开始搜索
					string subS = s.substr(tempBegin, *it);
					if (find(wordDict.begin(), wordDict.end(), subS) != wordDict.end()) {
						if (tempBegin + *it >= strSize) {
							return true;
						}
						myQueue.push(tempBegin + *it);
					}
				}
			}
		}

		return false;
    }
};
```

## 动态规划

### 思路

使用数组dp记录每个位置能都被拆分。***dp\[i\]***用于表示以 ***0 ~ i-1*** 为下标范围的字符串能否被字典拆分。

如果 ***0 ~ j-1*** 范围的字符串在字典中，即***dp\[j\] = true***，那么此时：

- 如果 ***j ~ i - 1*** 范围的字符串也在字典中，则 ***0 ~ i - 1*** 范围的字符串可以被字典拆分（拆分为 ***0 ~ j - 1` 与 `j ~ i - 1***），标记 ***dp\[i\] = true***。
- 如果 ***j ~ i - 1***范围的字符串不在字典中，继续判断 ***dp[j + 1]*** 与**j + 1 ~ i**范围字符的情况。

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int strLen = s.size();
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }

        // dp[i]表示以 0 ~ i-1 为下标范围的字符串能否被字典拆分
        vector<bool> dp(strLen + 1, false); // 因为还要包括0个字符的情况，所以dp数组的长度为s.size() + 1
        dp[0] = true;
        for (int i = 0; i <= strLen; ++i) {
            for (int j = 0; j < i; ++j) {
                // 在 j 处拆分字符串，看能否拆分为两个在字典中的单词
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

### 优化

j的不需要从0开始，只需要是***i - 字典中单词的最大长度***即可，因为当***i - j > 字典中单词的最大长度，子串肯定不匹配***。

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int strLen = s.size();
        if (s.empty()) {
            return true;
        }
        if (wordDict.empty()) {
            return false;
        }
        int maxWordLen = 0; // 记录字典中单词的最大长度
        for (auto it = wordDict.begin(); it != wordDict.end(); ++it) {
            maxWordLen = max(maxWordLen, static_cast<int>(it->size()));
        }

        // dp[i]表示以 0 ~ i-1 为下标范围的字符串能否被字典拆分
        vector<bool> dp(strLen + 1, false); // 因为还要包括0个字符的情况，所以dp数组的长度为s.size() + 1
        dp[0] = true;
        for (int i = 0; i <= strLen; ++i) {
            for (int j = max(0, i - maxWordLen); j < i; ++j) {
                // 在 j 处拆分字符串，看能否拆分为两个在字典中的单词
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

