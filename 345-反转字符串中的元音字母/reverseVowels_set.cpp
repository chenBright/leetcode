#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> charSet{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0;
        int j = s.size();
        while (i < j) {
            // 从左边查找元音字母
            while (i < j && charSet.find(s[i]) == charSet.end()) {
                ++i;
            }

            // 从右边查找元音字母
            while (j > i && charSet.find(s[j]) == charSet.end()) {
                --j;
            }

            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }

        return s;
    }
};