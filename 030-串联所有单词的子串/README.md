# 030-串联所有单词的子串

## 题目

leetcode：[030-串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)

## 哈希表 + 固定长度的滑动窗口

时间复杂度：***O(n^2)***。

### 实现1

先使用哈希表统计每个单词出现的次数。使用一个固定长度（单词长度 * 单词个数）的滑动窗口在`s`上滑动。滑动窗口没滑动一次，拷贝哈希表，从滑动窗口最左边开始切分单词。

- 如果滑动窗口内出现的单词在哈希表中，则哈希表该单词对应的value减1；
- 否则，该窗口不符合条件，直接滑动滑动窗口。

***该实现会超时。***

```c++
class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result;
        if (s.empty() || words.empty()) {
            return result;
        }

        unordered_map<string, int> wordMap;
        for (const auto &word : words) {
            if (wordMap.count(word) == 0) {
                wordMap[word] = 1;
            } else {
                ++wordMap[word];
            }
        }
        int wordLength = words[0].size();
        int totalWordsLength = words.size() * wordLength;
        for (int i = 0; i <= static_cast<int>(s.size()) - totalWordsLength; ++i) {
            int start = i;
            int end = i + totalWordsLength;
            unordered_map<string, int> tmpMap(wordMap.begin(), wordMap.end());

            while (start < end) {
                string tmp(s.begin() + start, s.begin() + start + wordLength);
                if (tmpMap.count(tmp) != 0 && tmpMap[tmp] > 0) {
                    start += wordLength;
                    --tmpMap[tmp];
                } else {
                    break;
                }
            }

            if (start == end) {
                result.push_back(i);
            }
        }

        return result;
    }
};
```

### 实现2

实现1拷贝哈希表的操作没有利用哈希表的查找为O(1)的优点，拷贝之后再在该哈希表上查找的话，主要工作在拷贝，跟直接在数组上查找的时间复杂度一样。

现在换种思路，不需要对原哈希表做减法，只需要为滑动窗口内的单词简历一个新的哈希表，再比较两个哈希表即可。

```c++
class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result;
        if (s.empty() || words.empty()) {
            return result;
        }

        unordered_map<string, int> wordMap;
        for (const auto &word : words) {
            ++wordMap[word];

        }
        int wordLength = words[0].size();
        int totalWordsLength = words.size() * wordLength;
        for (int i = 0; i <= static_cast<int>(s.size()) - totalWordsLength; ++i) {
            int start = i;
            int end = i + totalWordsLength;
            unordered_map<string, int> tmpMap;

            while (start < end) {
                string tmp(s.begin() + start, s.begin() + start + wordLength);
                if (wordMap.count(tmp) == 0) {
                    break;
                }
                ++tmpMap[tmp];
                if (tmpMap[tmp] > wordMap[tmp]) {
                    break;
                }
                start += wordLength;
            }

            if (start == end) {
                result.push_back(i);
            }
        }

        return result;
    }
};
```
