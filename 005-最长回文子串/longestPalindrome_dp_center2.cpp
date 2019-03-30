#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if (length == 0 || length == 1) {
            return s;
        }

        // indexs[0]为回文串起点，indexs[1]为回文串终点
        vector<int> indexs(2, 0);
        // dp[i][j] 表示s[i...j]是否是回文串
        vector<vector<bool> > dp(length, vector<bool>(length, false));
        
        for (int i = 0; i < length; ++i) { // i为终点
            int j = i; // j为起点
            while (j >= 0) {
                /**
                 * 如果：
                 * 1. s[j]和s[i]相邻 或者 i == j
                 * 或者
                 * 2. 在s[j]和s[i]相等的前提下，若dp[j+1][i-1]为真，即它们之间的字符串为回文串，
                 * 则j到i为回文串
                 */
                if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j >= indexs[1] - indexs[0]) {
                        indexs[0] = j;
                        indexs[1] = i;
                    }
                }
                --j;
            }
        }

        return string(s.begin() + indexs[0], s.begin() + indexs[1] + 1);
    }
};
