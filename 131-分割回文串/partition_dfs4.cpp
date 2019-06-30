#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        if (s.empty()) {
            return {{}}; // 避免返回后，在 for 中无遍历元素，导致结果为空数组
        }

        vector<vector<string> > result;
        for (int i = 0; i < s.size(); ++i) {
            if (!isPalindromic(s, 0, i)) {
                continue;
            }

            for (auto &item : partition(s.substr(i + 1))) {
                item.insert(item.begin(), s.substr(0, i + 1));
                result.push_back(item);
            }
        }

        return result;
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