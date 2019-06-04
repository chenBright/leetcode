#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 二分查找
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int strsSize = strs.size();
        if (strsSize == 0) {
            return "";
        } else if (strsSize == 1) {
            return strs[0];
        }

        int minLen = INT_MAX;
        for (string str : strs) {
            minLen = min(minLen, (int)str.size());
        }

        /**
         * low不取0，high不取minLen - 1
         * 因为low，high表示长度，将作为isCommonPrefix的第二个参数
         */
        int low = 1;
        int high = minLen;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isCommonPrefix(strs, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return strs[0].substr(0, (high + low) / 2); // 此时，low > high

    }

private:
    // 检查字符串数组中，第一个字符串长度为len的前缀是不是字符串数组所有字符串的公共前缀
    bool isCommonPrefix(vector<string> &strs, int len) {
        string prefix = strs[0].substr(0, len);

        for (string str : strs) {
            if (!startWith(str, prefix)) {
                return false;
            }
        }

        return true;
    }

    // 检查字符串prefix是不是字符串str的前缀
    bool startWith(string str, string prefix) {
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
