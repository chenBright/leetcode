#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int mS2T[256] = {0};
        int mT2S[256] = {0};
        for (int i = 0; i < s.size(); ++i) {
            if (mS2T[s[i]] != mT2S[t[i]]) {
                return false;
            }

            mS2T[s[i]] = i + 1; // 因为数组默认值为 0，代表没有替换
            mT2S[t[i]] = i + 1;
        }
        
        return true;
    }
};
