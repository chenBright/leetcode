#include <string>
#include <queue>
#include <algorithm>
using namespace std;

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