#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string tmpStr = "";

        dfs(s, 0, result, tmpStr, 0);

        return result;
    }

private:
    void dfs(string& s, int index, vector<string>& result, string& tmpStr, int num) {
        int length = s.size();
        if (num == 4) {
            if (index == length) {
                result.push_back(tmpStr);
            }
            return;
        }

        if (num > 0) {
            tmpStr += ".";
        }

        for (int i = 0; i < 3 && index + i < length; ++i) {
            string tmp(s.begin() + index, s.begin() + index + i + 1);
            if (valid(tmp)) {
                tmpStr += tmp;
                dfs(s, index + i + 1, result, tmpStr, num + 1);
                tmpStr.erase(tmpStr.size() - (i + 1), i + 1); // 删除 tmp
            } else {
                break;
            }
        }

        if (num > 0) {
            tmpStr.pop_back(); // 删除 “.”
        }
    }

    bool valid(string& s) {
        int length = s.size();
        if (s.empty() || length > 3 || (length > 1 && s[0] == '0')) {
            return false;
        }

        int n = atoi(s.c_str());
        return n <= 255;
    }
};
