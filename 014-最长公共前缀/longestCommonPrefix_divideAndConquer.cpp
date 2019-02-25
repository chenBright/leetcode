#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 分治
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int strsSize = strs.size();
        if (strsSize == 0) {
            return "";
        } else if (strsSize == 1) {
            return strs[0];
        }

        return longestCommonPrefix(strs, 0, strsSize - 1);
    }

private:
    // 查找最长公共前缀
    string longestCommonPrefix(vector<string> &strs, int left, int right) {
        if (left == right) {
            return strs[left];
        } 
        else if (left > right) {
            return "";
        }

        int mid = (left + right) / 2;
        string leftStr = longestCommonPrefix(strs, left, mid); // 查找左半边字符串的最长公共前缀
        string rightStr = longestCommonPrefix(strs, mid + 1, right); // 查找右半边字符串的最长公共前缀
        
        return commonPrefix(leftStr, rightStr); // 左右两部分的最长公共前缀
    }

    string commonPrefix(string left, string right) {
        int minSize = min(left.size(), right.size());

        for (int i = 0; i < minSize; ++i) {
            if (left[i] != right[i]) {
                return left.substr(0, i);
            }
        }

        return left.substr(0, minSize);
    }
};
