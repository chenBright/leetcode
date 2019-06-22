#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        vector<string> result;
        unordered_map<string, int> m;
        for (int i = 0; i + 9 < len; ++i) {
            string tmp(s.substr(i, 10));
            if (m.count(tmp)) {
                ++m[tmp];
            } else {
                m[tmp] = 1;
            }
        }

        for (const auto &item : m) {
            if (item.second > 1) {
                result.push_back(item.first);
            }
        }

        return result;
    }
};
