#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.size();
        int length2 = text2.size();
        vector<int> dp(length2 + 1, 0); // 将 dp 数组压缩档一维
        for (int i = 0; i < length1; ++i) {
            int last = dp[0]; // 记录上一行左上角的值，即 [i - 1][j - 1] 位置上的值。
            int now = 0;
            for (int j = 0; j < length2; ++j) {
                now = dp[j + 1]; // 记录上一行 j + 1 位置的值。
                if (text1[i] == text2[j]) {
                    dp[j + 1] = last + 1;
                } else {
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                }
                last = now;
            }
        }

        return dp[length2];
    }
};
