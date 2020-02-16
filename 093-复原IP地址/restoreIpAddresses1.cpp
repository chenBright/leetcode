#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;

        dfs(s, 0, result, "", 0);

        return result;
    }

private:
    void dfs(string& s, int index, vector<string>& result, string tmpStr, int num) {
        int length = s.size();
        if (num == 4) {
            if (index == length) {
                result.push_back(tmpStr);
            }
            return;
        }

        for (int i = 0; i < 3 && i < length; ++i) {
            string tmp(s.begin() + index, s.begin() + index + i + 1);
            if (valid(tmp)) {
                dfs(s, index + i + 1, result, num == 0 ? tmp : tmpStr + "." + tmp, num + 1);
            } else {
                return;
            }
        }
    }

    bool valid(string& s) {
        int length = s.size();
        if (s.empty() || length > 3 || (length > 1 && s[0] == '0')) {
            return false;
        }

        int num = atoi(s.c_str());
        return num <= 255;
    }
};