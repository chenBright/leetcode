#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            res += (s[length - 1 - i] - 'A' + 1) * (int)pow(26, i);
        }

        return res;
    }
};