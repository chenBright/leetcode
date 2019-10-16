#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();
        
        vector<int> m(26, 0);
        for (const auto& c : s1) {
            ++m[c - 'a'];
        }

        int left = 0;
        int right = 0;
        int count = length1;
        while (right < length2) {
            if (--m[s2[right++] - 'a'] >= 0) {
                --count;
            }

            if (count == 0) {
                return true;
            }

            if (right - left == length1 && ++m[s2[left++] - 'a'] > 0) {
                ++count;
            }
        }

        return false;
    }
};
