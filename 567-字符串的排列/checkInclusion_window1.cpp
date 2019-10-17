#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();
        
        unordered_map<char, int> m;
        for (const auto& c : s1) {
            ++m[c];
        }

        int left = 0;
        int right = 0;
        int count = length1;
        while (right < length2) {
            if (m[s2[right++]]-- > 0) {
                --count;
            }

            if (count == 0) {
                return true;
            }

            if (right - left == length1 && ++m[s2[left++]] > 0) {
                ++count;
            }
        }

        return false;
    }
};
