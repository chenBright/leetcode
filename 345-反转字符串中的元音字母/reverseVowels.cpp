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
            while (i < j && isVowel(s[i])) {
                ++i;
            }

            // 从右边查找元音字母
            while (j > i && isVowel(s[j])) {
                --j;
            }

            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }

        return s;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I'  || c == 'O' || c == 'U';
    }
};