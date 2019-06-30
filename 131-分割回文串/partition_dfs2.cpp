#include <vector>
#include <string>
using namespace std;

// 使用数组记录字符串是否为回文字符串
class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return result;
        }

        int len = s.size();
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        for (int i =0; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (s[i] ==s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                }
            }
        }

        partitionRecursion(s, 0, dp);

        return result;
    }

private:
    vector<vector<string> > result;
    vector<string> tmpResult;

    void partitionRecursion(string &s, int index, vector<vector<bool> > &dp) {
        int len = s.size();
        if (index >= len) {
            result.push_back(tmpResult);
        }

        for (int i = index; i < len; ++i) {
            if (dp[index][i]) {
                tmpResult.push_back(s.substr(index, i - index + 1));
                partitionRecursion(s, i + 1, dp);
                tmpResult.pop_back();
            }
        }
    }
};