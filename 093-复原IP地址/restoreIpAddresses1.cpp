#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty()) {
            return result;
        }

        dfs(s, "", 0);

        return result;
    }

private:
    vector<string> result;

    void dfs(string s, string tmpStr, int num) {
        if (num == 4) {
            if (s.empty()) {
                result.push_back(tmpStr);
            }
            return;
        }

        int len = s.size();
        for (int i = 0; i < 3 && i < len; ++i) {
            string tmp(s.begin(), s.begin() + i + 1);
            if (valid(tmp)) {
                dfs(s.substr(i + 1, len - i - 1), num == 0 ? tmp : tmpStr + "." + tmp, num + 1);
            } else {
                return;
            }
        }
    }

    bool valid(string s) {
        int len = s.size();
        if (s.empty() || len > 3 || (len > 1 && s[0] == '0')) {
            return false;
        }
        
        int n = atoi(s.c_str());
        return n <= 255 ? true : false;
    }
};
