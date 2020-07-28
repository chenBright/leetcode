#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }
private:
    bool isMatch(const string &s, int sIndex, const string &p, int pIndex) {
        int sLen = s.size();
        int pLen = p.size();
        if (pIndex == pLen) {
            return sIndex == sLen;
        }

        if (pIndex + 1 == pLen) {
            return sIndex + 1 == sLen && (s[sIndex] == p[pIndex] || p[pIndex] == '.');
        }

        if (p[pIndex + 1] != '*') {
            if (sIndex == sLen) {
                return false;
            }

            return (s[sIndex] == p[pIndex] || p[pIndex] == '.') && isMatch(s, sIndex + 1, p, pIndex + 1);
        }

        while (sIndex < sLen && (s[sIndex] == p[pIndex] || p[pIndex] == '.')) {
            if (isMatch(s, sIndex, p, pIndex + 2)) {
                return true;
            }
            ++sIndex;
        }

        // 不匹配，则跳过 p[pIndex] 和 p[pIndex](*)
        return isMatch(s, sIndex, p, pIndex + 2);
    }
};
