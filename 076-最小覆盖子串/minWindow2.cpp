#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (const auto& c : t) {
            ++m[c];
        }

        int left = 0;
        int right = 0;
        int count = t.size();
        int minLeft = -1;
        int minLenght = INT_MAX;
        while (right < s.size()) {
            if (m[s[right++]]-- >= 1) {
                --count;
            }

            while (count == 0) {
                if (minLenght > right - left) {
                    minLeft = left;
                    minLenght = right - left;
                }

                if (m[s[left++]]++ >= 0) {
                    ++count;
                }
            }
        }

        return minLeft == -1 ? "" : s.substr(minLeft, minLenght);
    }
};
