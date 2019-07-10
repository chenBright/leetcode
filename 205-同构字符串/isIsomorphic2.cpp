#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> mS2T;
        unordered_map<char, int> mT2S;
        for (int i = 0; i < s.size(); ++i) {
            if (mS2T.find(s[i]) == mS2T.end() && mT2S.find(t[i]) == mT2S.end()) {
                mS2T[s[i]] = i;
                mT2S[t[i]] = i;
            } else if (mS2T.find(s[i]) != mS2T.end() && mT2S.find(t[i]) != mT2S.end()) {
                if (mS2T[s[i]] != mT2S[t[i]]) {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        return true;
    }
};
