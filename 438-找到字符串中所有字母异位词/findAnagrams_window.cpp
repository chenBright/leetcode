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

        int left = 0;
        int right = 0;
        int count = p.size(); // 滑动窗口中已经匹配的字母数 = p.size() - count
        // 滑动窗口的范围 [left, right)
        while (right < s.size()) {
            // right 位置的字符存在于 p 中
            // 移动滑动窗口的右边界
            if (m[s[right++] - 'a']-- >= 1) {
                --count;
            }

            if (count == 0) {
                result.push_back(left);
            }

            // 窗口长度为 p.size() 且 left 位置存在于 p 中
            // 移动滑动窗口的左边界
            if (right - left == p.size() && m[s[left++] - 'a']++ >= 0) {
                ++count;
            } 
        }

        return result;
    }
};
