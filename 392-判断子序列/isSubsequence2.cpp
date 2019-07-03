#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 后续挑战
class Solution {
public:
    vector<bool> isSubsequence(vector<string> strs, string t) {
        if (t.empty()) {
            return vector<bool>(strs.size(), false);
        }

        unordered_map<char, vector<int> > m;
        for (int i = 0; i < t.size(); ++i) {
            m[t[i]].push_back(i);
        }

        vector<bool> result(strs.size(), true);
        for (int j = 0; j < strs.size(); ++j) {
            string s = strs[j];
            int preIndex = 0;
            for (int k = 0; k < s.size(); ++k) {
                vector<int> v = m[s[k]];
                // 查找第一个大于等于 preIndex 的值
                auto it = lower_bound(v.begin(), v.end(), preIndex);
                if (it == v.end()) { // 没有找到，则不是子序列
                    result[j] = false;
                    break;
                }
                // 如果 *it == preIndex，表示 s[k] == s[k - 1]，
                // 则迭代器需要指向下一个值，该值才是 s[k] 对应的索引值
                if (*it == preIndex) {
                    ++it;
                    if (it == v.end()) {
                        result[j] = false;
                        break;
                    }
                }
                preIndex = *it;
            }
        }

        return result;
    }
};