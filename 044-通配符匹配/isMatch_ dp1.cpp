#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 1];
            }
        }

        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (p[k - 1] == '*') {
                    dp[j][k] = dp[j - 1][k] || dp[j][k - 1];
                } else {
                    dp[j][k] = (s[j - 1] == p[k - 1] || p[k - 1] == '?') && dp[j - 1][k - 1];
                }
            }
        }

        return dp[m][n];
    }
};
