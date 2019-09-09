#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0) > 1;
    }

private:
    int helper(string &s, string &p, int i, int j) {
        if (i == s.size() && j == p.size()) {
            return 2;
        }

        if (i == s.size() && p[j] != '*') {
            return 0;
        }

        if (j == p.size()) {
            return 1;
        }

        if (s[i] == p[j] || p[j] == '?') {
            return helper(s, p, i + 1, j + 1);
        }

        if (p[j] == '*') {
            if (j + 1 < p.size() && p[j + 1] == '*') {
                return helper(s, p, i, j + 1);
            }

            for (int k = 0; k <= static_cast<int>(s.size()) - i; ++k) {
                int result = helper(s, p, i + k, j + 1);
                if (result == 0 || result == 2) {
                    return result;
                }
            }
        }

        return 1;
    }
};
