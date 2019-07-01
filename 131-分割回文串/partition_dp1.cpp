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
        // dp[i+1]={dp[i] + s[i+1], dp[i-1] + s[i..i+1], ... , dp[0] + s[1..i+1], s[0..i+1]}
        vector<vector<vector<string> > > dp(len);
        dp[0].push_back(vector<string>(1, string(1, s[0])));
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!isPalindromic(s, j + 1, i)) {
                    continue;
                }
                // 和 dp[i] 组合
                for (const auto &item : dp[j]) {
                        dp[i].push_back(item);
                        dp[i].rbegin()->push_back(s.substr(j + 1, i - j));
                }
            }
            // 如果 s[0..i] 是回文字符串，则整段分割
            if (isPalindromic(s, 0, i)) {
                dp[i].push_back(vector<string>(1, s.substr(0, i + 1)));
            }
        }

        return *(dp.rbegin());
    }

private:
    // s[start …… end]是否为回文字符串
    bool isPalindromic(string &s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }

        return true;
    }

};