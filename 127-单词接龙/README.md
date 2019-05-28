# 127-单词接龙

## 题目

leetcode：[127-单词接龙](https://leetcode-cn.com/problems/word-ladder/)

## BFS

该题目需要***去重***。例如：

```
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
```

除了最短路径，还会出现以下路径：

```
"hit" -> "hot" -> "lot" -> "dot" -> "dog" -> "cog"
```

在***第3层***，找到`lot`、`dot`两个单词，如果不同时删除这两个单词，则在`"hit" -> "hot" -> "lot"`路径下一层也会选择`dot`，明显与上一层重复，且路径更长。所以每一层选好单词后，直接同时删除这些单词即可。

### 思路1

使用队列进行`BFS`：

- 每次一个单词出队列，没找到一个符合条件的单词就将找到的单词入队。
- 使用变量`lastRightWord`记录上一层的最后的结点，变量`rightWord`记录当前遍历层的最后结点。如果***word == lastRightWord***，表示遍历完一层，更新 `lastRightWord`和层数`res`。
- 如果匹配到`endWord`，则返回`res + 1`。
- 当队列为空，结束循环。

此处验证两个单词的方法是：在遍历候选单词列表`wordList`，找出与当前单词能相互转换的单词。此步骤的时间复杂度为***O(n \* word.size())***。

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) != wordList.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        string lastRightWord = beginWord;
        string rightWord = "";
        int res = 0;
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            vector<string>::iterator it = wordList.begin();
            while (it != wordList.end()) {
                if (isNextWord(word, *it)) {
                    if (*it == endWord) {
                        return res + 1;
                    }

                    q.push(*it);
                    rightWord = *it;
                    /**
                     * 去重，此处被选择的单词，可能出现在“此层”其他单词后面.
                     * 但是肯定比此时的路径要长，所以直接剪枝。
                     * 如
                     * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
                     * "hit" -> "hot" -> "lot" -> "dot" -> "dog" -> "cog"
                     */
                    it = wordList.erase(it);
                } else {
                    ++it;
                }
            }

            // 遍历完一层
            if (word == lastRightWord) {
                lastRightWord = rightWord;
                ++res;
            }
        }

        return 0;
    }

private:
    bool isNextWord(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        int count = 0;
        for (int i = 0; i < word1.size(); ++i) {
            if (count > 1) {
                return false;
            }
            if (word1[i] != word2[i]) {
                ++count;
            }
        }

        return count == 1 ? true : false;
    }
};
```

### 思路2

使用哈希表保存单词，可以加快单词查找的速度。

但使用思路1的验证两个单词方法会超时，应该是有的测试用例数据量比较大。

换一种验证方法：用`a-z`26个字母分别替换当前单词的每个位置的字母，然后去候选单词列表`wordDict`查找是否存在该单词。因为哈希表查找的时间复杂度为***O(1)***，所以该步骤的时间复杂度为***O(26 \* word.size())***。

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if (wordDict.find(endWord) == wordDict.end()) {
            return 0;
        }

        unordered_set<string> beginSet{beginWord};
        int res = 1;
        while (!beginSet.empty()) {
            unordered_set<string> tempSet;
            ++res;
            /**
             * 去重，此处被选择的单词，可能出现在“此层”其他单词后面.
             * 但是肯定比此时的路径要长，所以直接剪枝。
             * 如
             * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
             * "hit" -> "hot" -> "lot" -> "dot" -> "dog" -> "cog"
             */
            for (const auto &beginWord : beginSet) {
                wordDict.erase(beginWord);
            }

            // 用 a-z 替换每个位置的字母，然后在 wordDict 中查找
            for (auto &beginWord : beginSet) {
                for (int i = 0; i < beginWord.size(); ++i) {
                    string str = beginWord;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        str[i] = c;
                        if (wordDict.find(str) != wordDict.end()) {
                            if (str == endWord) {
                                return res;
                            }
                            tempSet.insert(str);
                        }
                    }
                }
            }
            beginSet = tempSet;           
        }

        return 0;
    }
};
```

### 思路3

[参考LeetCode评论区 江南花家第七子 的思路](https://leetcode-cn.com/problems/word-ladder/comments/21107)。在思路2的基础上优化：***两端搜索***。

例如：

- 假设从`beginWord`转换为`endWord`，存在于字典中的，（第一个）中间结果有`30`个。
- 而，从`endWord`转换为`beginWord`，存在于字典中的，（第一个）中间结果只有`2`个。
- 那么，很显然。从`endWord`开始会更快。所以，每次都从个数少的那块开始替换一位。

因此，我们每次都从中间结果少的那一端出发，这样就能剪枝掉很多不必要的搜索过程。

```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if (wordDict.find(endWord) == wordDict.end()) {
            return 0;
        }

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        int res = 1;
        while (!beginSet.empty()) {
            unordered_set<string> tempSet;
            ++res;
            /**
             * 去重，此处被选择的单词，可能出现在“此层”其他单词后面.
             * 但是肯定比此时的路径要长，所以直接剪枝。
             * 如
             * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
             * "hit" -> "hot" -> "lot" -> "dot" -> "dog" -> "cog"
             */
            for (const auto &beginWord : beginSet) {
                wordDict.erase(beginWord);
            }

            for (auto &beginWord : beginSet) {
                for (int i = 0; i < beginWord.size(); ++i) {
                    string str = beginWord;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        str[i] = c;
                        if (wordDict.find(str) != wordDict.end()) {
                            if (endSet.find(str) != endSet.end()) {
                                return res;
                            }
                            tempSet.insert(str);
                        }
                    }
                }
            }

            if (tempSet.size() < endSet.size()) {
                beginSet = tempSet;
            } else {
                beginSet = endSet;
                endSet = tempSet;
            }
        }

        return 0;
    }
};
```

