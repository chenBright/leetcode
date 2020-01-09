#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        // indexs[0] 为回文串起点，indexs[1] 为回文串终点
        vector<int> indexs(2, 0);
        // dp[i][j] 表示 s[i...j] 是否是回文串
        vector<vector<bool> > dp(length, vector<bool>(length, false));

        for (int i = 0; i < length; ++i) { // i 为终点
            // j 为起点
            for (int j = i; j >= 0; --j) {
                /**
                 * 如果：
                 * 1. s[j] 和 s[i] 相邻 或者 i == j
                 * 或者
                 * 2. 在 s[j] 和 s[i] 相等的前提下，若 dp[j+1][i-1] 为真，即它们之间的字符串为回文串，
                 * 则 j 到 i 为回文串。
                 */
                if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j >= indexs[1] - indexs[0]) {
                        indexs[0] = j;
                        indexs[1] = i;
                    }
                }
            }
        }

        return s.substr(indexs[0], indexs[1] - indexs[0] + 1);
    }
};
