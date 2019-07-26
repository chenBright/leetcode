#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (m.count(s[i]) == 0) {
                m[s[i]] = 1;
            } else {
                ++m[s[i]];
            }
        }

        for (int j = 0; j < t.size(); ++j) {
            if (m.count(t[j]) == 0 || --m[t[j]] < 0) {
                return false;
            }
        }


        return true;
    }
};