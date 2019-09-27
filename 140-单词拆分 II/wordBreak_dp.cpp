#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

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
