#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        // dp[i][j] 表示 s[i :] 和 p[j - 1 :] 是否匹配
        vector<vector<bool> > dp(sLen + 1, vector<bool>(pLen + 1, false));
        dp[sLen][pLen] = true;

        // 从 sLen 开始，因为匹配是到这一步才结束
        for (int i = sLen; i >= 0; --i) { // 注意：从 sLen 开始
            for (int j = pLen - 1; j >= 0; --j) {
                bool firstMatch = i < sLen && (s[i] == p[j] || p[j] == '.');
                if (j + 1 < pLen && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
                } else {
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};
