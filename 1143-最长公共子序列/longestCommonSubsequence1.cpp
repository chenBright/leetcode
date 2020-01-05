#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.size();
        int length2 = text2.size();
        vector<vector<int> > dp(length1 + 1, vector<int>(length2 + 1, 0));
        for (int i = 0; i < length1; ++i) {
            for (int j = 0; j < length2; ++j) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    // dp[i][j] 肯定小于 dp[i + 1][j] 和 dp[i][j + 1]
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[length1][length2];
    }
};
