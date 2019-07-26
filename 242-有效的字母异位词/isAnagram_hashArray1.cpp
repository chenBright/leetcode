#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int sMap[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++sMap[s[i] - 'a'];
        }

        int tMap[26] = {0};
        for (int j = 0; j < t.size(); ++j) {
            ++tMap[t[j] - 'a'];
        }

        for (int k = 0; k < 26; ++k) {
            if (sMap[k] != tMap[k]) {
                return false;
            }
        }

        return true;

    }
};