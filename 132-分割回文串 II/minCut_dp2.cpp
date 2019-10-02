#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.empty()) {
            return 0;
        }

        int length = s.size();
        // dp[i] 表示由s串中前 i 个字母的最小分割方案。
        vector<int> dp(length + 1, INT_MAX);
        dp[0] = -1;
        for (int i = 0; i < length; ++i) {
            // 回文字符串的字符数是奇数的情况
            // 以 i 为中心向两边扩展
            for (int len = 0; i - len >= 0 && i + len < length && s[i - len] == s[i + len]; ++len) {
                // 扩展到 i + len + 1，可以确定 [i - len ... i + len + 1] 是回文字符串。
                // - 已经找到的 [0 ... i + len + 1] 最小分割方案；
                // - [0 ... i - len - 1]、[i - len ... i + len + 1] 分割方案；
                // 中，去最小的方案。
                dp[i + len + 1] = min(dp[i + len + 1], dp[i - len] + 1);
            }

            // 回文字符串的字符数是偶数的情况
            // 以 i，i + 1 为中心向两边扩展
            for (int len = 0; i - len >= 0 && i + len + 1 < length && s[i - len] == s[i + len + 1]; ++len) {
                // 扩展到 i + len + 2，可以确定 [i - len ... i + len + 2] 是回文字符串。
                // - 已经找到的 [0 ... i + len + 2] 最小分割方案；
                // - [0 ... i - len - 1]、[i - len ... i + len + 2] 分割方案；
                // 中，去最小的方案。
                dp[i + len + 2] = min(dp[i + len + 2], dp[i - len] + 1);
            }
        }

        return dp[length];
    }
};
