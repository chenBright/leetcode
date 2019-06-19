#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        // 题目已经假设字符串不为空，所以可以不做判空（速度提升1倍）
        if (len1 == 0 && len2 == 0) {
            return 0;
        } else if (len1 == 0) {
            return -1;
        } else if (len2 == 0) {
            return 1;
        }

        int i = 0;
        int j = 0;
        // 比较对应位置上的版本号
        while (i < len1 && j < len2) {
            int m = i;
            while (m < len1 && version1[m] != '.') {
                ++m;
            }
            int num1 = stoi(version1.substr(i, m - i));
            i = m + 1;

            int n = j;
            while (n < len2 && version2[n] != '.') {
                ++n;
            }
            int num2 = stoi(version2.substr(j, n - j));
            j = n + 1;

            if (num1 != num2) {
                return num1 > num2 ? 1 : -1;
            }
        }

        if (i >= len1 && j >= len2) { // 两个字符串长度一样
            return 0;
        } else if (i >= len1) { // version2 比 version1 长
            while (j < len2) { // 如果后面的字符中存在 非 '.' 和 非 '0' 的字符，即 '1~9'，则 version2 版本号大，否则，相等
                if (version2[j] != '.' && version2[j] != '0') {
                    return -1;
                }
                ++j;
            }
            return 0;
        } else {
            while (i < len1) {
                if (version1[i] != '.' && version1[i] != '0') { // 同上
                    return 1;
                }
                ++i;
            }
            return 0;
        }
    }
};
