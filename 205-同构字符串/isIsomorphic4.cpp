#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (s.find(s[i]) != t.find(t[i])) {
                return false;
            }
        }
        
        return true;
    }
};
