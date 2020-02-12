#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 二分查找
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
        for (string str : strs) {
            minLength = min(minLength, static_cast<int>(str.size()));
        }

        int low = 0;
        int high = minLength - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isCommonPrefix(strs, mid + 1)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return strs[0].substr(0, low);

    }

private:
    // 检查字符串数组中，第一个字符串长度为 len 的前缀是不是字符串数组所有字符串的公共前缀
    bool isCommonPrefix(vector<string>& strs, int length) {
        string prefix = strs[0].substr(0, length);

        for (string str : strs) {
            if (!startWith(str, prefix)) {
                return false;
            }
        }

        return true;
    }

    // 检查字符串prefix是不是字符串str的前缀
    bool startWith(string& str, string& prefix) {
        if (str.size() < prefix.size()) {
            return false;
        }

        for (int i = 0; i < prefix.size(); ++i) {
            if (prefix[i] != str[i]) {
                return false;
            }
        }

        return true;
    }
};
