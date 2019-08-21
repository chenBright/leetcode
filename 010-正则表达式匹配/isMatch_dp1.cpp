#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i][j] 表示 s[i :] 和 p[j - 1 :] 是否匹配 
        vector<vector<int> > dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return isMatch(s, 0, p, 0, dp);
    }

private:
    bool isMatch(string &s, int sIndex, string &p, int pIndex, vector<vector<int> > &dp) {
        if (dp[sIndex][pIndex] >= 0) {
            return dp[sIndex][pIndex];
        }
        
        int sLen = s.size();
        int pLen = p.size();

        int result = -1;
        if (pIndex == pLen) {
            result = sIndex == sLen ? 1 : 0;
        } else {
            bool firstMatch = sIndex < sLen && (s[sIndex] == p[pIndex] || p[pIndex] == '.');
            if (pIndex + 1 < pLen && p[pIndex + 1] == '*') {
                result = isMatch(s, sIndex, p, pIndex + 2, dp) || (firstMatch && isMatch(s, sIndex + 1, p, pIndex, dp))  ? 1 : 0;
            } else {
                result = firstMatch && isMatch(s, sIndex + 1, p, pIndex + 1, dp)  ? 1 : 0;
            }
        }
        dp[sIndex][pIndex] = result;

        return result;
    }
};
