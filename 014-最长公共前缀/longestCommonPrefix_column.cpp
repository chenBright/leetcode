#include <string>
#include <vector>
using namespace std;

// 扫描列
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strsSize = strs.size();
        if (strsSize == 0) {
            return "";
        } else if (strsSize == 1) {
            return strs[0];
        }

        int minLength = INT_MAX;
        for (const auto& str : strs) {
            minLength = min(minLength, static_cast<int>(str.size()));
        }

        for (int i = 0; i < minLength; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strsSize; ++j) {
                if (strs[j][i] != c) {
                    strs[0].substr(0, i);
                }
            }
            ++i;
        }

        return strs[0].substr(0, minLength);
    }
};
