#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // 指向 s
        int j = 0; // 指向 t
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                ++i;
            }
            ++j;
        }

        return i == s.size();
    }
};