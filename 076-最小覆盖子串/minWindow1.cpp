#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string result = "";

        unordered_map<char, int> m;
        for (const auto& c : t) {
            ++m[c];
        }

        int left = 0;
        int right = 0;
        int count = t.size();
        int minLenght = INT_MAX;
        while (right < s.size()) {
            if (m[s[right++]]-- >= 1) {
                --count;
            }

            while (count == 0) {
                if (minLenght > right - left) {
                    minLenght = right - left;
                    result = s.substr(left, minLenght);
                }

                if (m[s[left++]]++ >= 0) {
                    ++count;
                }
            }
        }

        return result;
    }
};
