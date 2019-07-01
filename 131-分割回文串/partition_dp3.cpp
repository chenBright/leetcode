#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return vector<vector<string> >();
        }

        int len = s.size();
    
        // dp[i] 表示 s[0..i]的分割组合
        // dp[0] 表示空组合，为了不需要单独处理 s[0..i] 不分割的情况，，dp[0] + s[1..i+1]即为不分割的情况
        // dp[i+1]={dp[i] + s[i+1], dp[i-1] + s[i..i+1], ... , dp[0] + s[1..i+1]}
        vector<vector<vector<string> > > dp(len + 1);
        // palindromicDp[j][i] 表示 s[j..i] 是否为回文字符串
        vector<vector<bool> > palindromicDp(len, vector<bool>(len, false));
        dp[0].push_back({});
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                // 和 dp[i] 组合
                for (const auto &item : dp[j]) {
                    if (s[i] == s[j] && (i - j < 2 || palindromicDp[j + 1][i - 1])) {
                        palindromicDp[j][i] = true; // j <= i

                        dp[i + 1].push_back(item);
                        dp[i + 1].rbegin()->push_back(s.substr(j, i - j + 1));
                    }
                }
            }
        }

        return *(dp.rbegin());
    }
};