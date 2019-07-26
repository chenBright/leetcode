#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int m[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++m[s[i] - 'a'];
        }

        for (int j = 0; j < t.size(); ++j) {
            if (--m[t[j] - 'a'] < 0) {
                return false;
            }
        }

        return true;

    }
};