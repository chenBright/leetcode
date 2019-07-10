#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> mS2T;
        unordered_map<char, char> mT2S;
        for (int i = 0; i < s.size(); ++i) {
            if (mS2T.find(s[i]) == mS2T.end() && mT2S.find(t[i]) == mT2S.end()) { // 没有替换过
                mS2T[s[i]] = t[i];
                mT2S[t[i]] = s[i];
            } else if (mS2T.find(s[i]) != mS2T.end() && mT2S.find(t[i]) != mT2S.end()) {
                if (mS2T[s[i]] != t[i]) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};
