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

        vector<int> m1(26, 0), m2(26, 0);
        for (int i = 0; i < p.size(); ++i) {
            ++m1[s[i] - 'a'];
            ++m2[p[i] - 'a'];
        }
        if (m1 == m2) {
            result.push_back(0);
        }

        for (int i = 1; i < static_cast<int>(s.size()) - static_cast<int>(p.size()) + 1; ++i) {
            // 移动固定长度（p.size()）的滑动窗口
            ++m1[s[i + p.size() - 1] - 'a'];
            --m1[s[i - 1] - 'a'];

            if (m1 == m2) {
                result.push_back(i);
            }
        }

        return result;
    }
};
