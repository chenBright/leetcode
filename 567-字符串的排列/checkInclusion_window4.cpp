#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();

        vector<int> m(26, 0);
        for (const auto& c : s1) {
            ++m[c - 'a'];
        }

        int left = 0;
        int right = 0;
        // 滑动窗口：[left, right]
        while (right < length2) {
            if (--m[s2[right] - 'a'] < 0) {
                // 收缩 left，++m[s2[i] - 'a']
                // ++m[s2[i] - 'a'] < 0，表示该字符不是字符串的排列
                // 或者 i 后面已经出现该字符了，即该字符是多出来的
                while (++m[s2[left++] - 'a'] > 0);
            } else if (right - left + 1 == length1) {
                return true;
            }
            ++right;
        }

        return false;
    }
};
