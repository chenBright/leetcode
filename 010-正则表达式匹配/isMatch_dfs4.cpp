#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }

private:
    bool isMatch(string &s, int sIndex, string &p, int pIndex) {
        int sLen = s.size();
        int pLen = p.size();
        if (pIndex == pLen) {
            return sIndex == sLen;
        }

        bool firstMatch = sIndex < sLen && (s[sIndex] == p[pIndex] || p[pIndex] == '.');
        if (pIndex + 1 < pLen && p[pIndex + 1] == '*') {
            return isMatch(s, sIndex, p, pIndex + 2) || (firstMatch && isMatch(s, sIndex + 1, p, pIndex));
        } else {
            return firstMatch && isMatch(s, sIndex + 1, p, pIndex + 1);
        }
    }
};
