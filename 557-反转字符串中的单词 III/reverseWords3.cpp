#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int length = s.size();
        for (int i = 0; i < length;) {
            int j = i + 1;
            while (j < length && s[j] != ' ') {
                ++j;
            }

            reverseWords(s, i, j - 1);

            i = j + 1;
            // 跳过空格
            while (i < length && s[i] == ' ') {
                ++i;
            }
        }

        return s;
    }

private:
    void reverseWords(string& s, int start, int end) {
        while (start < end) {
            s[start] ^= s[end];
            s[end] ^= s[start];
            s[start] ^= s[end];
            ++start;
            --end;
        }
    }
};
