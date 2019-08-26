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
