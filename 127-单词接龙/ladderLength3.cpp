#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

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