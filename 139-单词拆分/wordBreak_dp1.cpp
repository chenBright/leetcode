#include <string>
#include <vector>
#include <algorithm>
using namespace std;

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