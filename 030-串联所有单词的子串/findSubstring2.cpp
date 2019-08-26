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
