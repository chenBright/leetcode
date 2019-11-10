#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) {
            return 0;
        }

        int length = s.size();
        int result = 0;
        vector<vector<bool> > dp(length, vector<bool>(length, false));

        for (int i = length - 1; i >= 0; --i) {
            for (int j = i; j < length; ++j) {
                // 根据 [i + 1 ... j - 1] 判断 [i ... j] 是不是回文子串
                dp[i][j] = s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]);
                if (dp[i][j]) {
                    ++result;
                }
            }
        }

        return result;
    }
};
