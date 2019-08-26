#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

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
        for (int i = 0; i < wordLength; ++i) {
            int start = i;
            int end = i;
            int count = 0;
            unordered_map<string, int> tmpMap;

            while (end + wordLength <= s.size()) {
                string tmp(s.begin() + end, s.begin() + end + wordLength);
                ++tmpMap[tmp];
                end += wordLength;
                ++count; // 先加 1，如果该单词不在 wordMap 中，则在后面循环会减 1
                // 如果 tmp 出现在 wordMap 中，但是次数太大了，则向左移动滑动窗口的左边界（右边界不动）；
                // 如果 tmp 没出现在 wordMap 中，则滑动窗口的左边界会一直向左移动到与右边界重合。
                while (tmpMap[tmp] > wordMap[tmp]) {
                    string startTmp(s.begin() + start, s.begin() + start + wordLength);
                    --count;
                    --tmpMap[startTmp];
                    start += wordLength;
                }
                if (count == words.size()) {
                    result.push_back(start);
                }
            }
        }

        return result;
    }
};
