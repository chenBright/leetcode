#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        // dp[i][j] 表示 s[0 ... i - 1] 和 p[0 ... j - 1] 是否匹配
        vector<vector<bool> > dp(sLen + 1, vector<bool>(sLen + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= sLen; ++i) {
            for (int j = 1; j <= pLen; ++j) { // 注意：从 1 开始
                if (j > 1 && p[j - 1] == '*') {
                    // dp[i][j - 2] 表示匹配 0 个字符。
                    // dp[i - 1][j] 表示匹配 1 个字符，当循环 i = i + 1, j = j 时，继续匹配下一个字符。
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[sLen][pLen];
    }
};
