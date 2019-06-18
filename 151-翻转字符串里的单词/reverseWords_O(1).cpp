#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return "";
        }

        reverse(s.begin(), s.end());
        int storeIndex = 0, len = s.size();
        for (int i = 0; i < len; ++i) {
            if (s[i] != ' ') {
                int j = i;
                while (j < len && s[j] != ' ') {
                    ++j;
                }

                if (storeIndex != 0) {
                    s[storeIndex++] = ' ';
                }
                reverse(s.begin() + i, s.begin() + j);
                while (i != j) {
                    s[storeIndex++] = s[i++];
                }
            }
        }

        s.erase(s.begin() + storeIndex, s.end());
        return s;
    }
};