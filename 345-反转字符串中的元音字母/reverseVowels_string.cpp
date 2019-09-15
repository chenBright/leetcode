#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string dict("aAeEiIoOuU");
        int i = 0;
        int j = s.size();
        while (i < j) {
            // 从左边查找元音字母
            while (i < j && dict.find(s[i]) == string::npos) {
                ++i;
            }

            // 从右边查找元音字母
            while (j > i && dict.find(s[j]) == string::npos) {
                --j;
            }

            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }

        return s;
    }
};