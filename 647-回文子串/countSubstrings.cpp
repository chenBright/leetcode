#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) {
            return 0;
        }

        int length = s.size();
        int result = 0;
        for (int i = 0; i < length; ++i) {
            helper(s, i, i, result);
            helper(s, i, i + 1, result);
        }

        return result;
    }
private:
    void helper(string s, int i, int j, int& result) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
            ++result;
        }
    }
};
