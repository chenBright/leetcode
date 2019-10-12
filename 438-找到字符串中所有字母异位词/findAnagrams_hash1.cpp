#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.empty() || p.empty() || s.size() < p.size()) {
            return result;
        }

        vector<int> m(26, 0);
        for (int i = 0; i < p.size(); ++i) {
            ++m[p[i] - 'a'];
        }

        for (int i = 0; i < static_cast<int>(s.size()) - static_cast<int>(p.size()) + 1; ++i) {
            vector<int> tmp(m);
            bool flag = true;
            for (int j = 0; j < p.size(); ++j) {
                char c = s[i + j];
                if (--tmp[c - 'a'] < 0) { // 该字母不存在于 p 中
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result.push_back(i);
            }
        }

        return result;
    }
};
