#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> m; // <数字，所在连续序列的长度>
        int result = 0;
        for (const auto &num : nums) {
            if (m.count(num) == 0) {
                // num - 1 所在连续序列的长度
                int left = m.count(num - 1) ? m[num - 1] : 0;
                // num + 1 所在连续序列的长度
                int right = m.count(num + 1) ? m[num + 1] : 0;
                int tmpResult = left + 1 + right;
                // 更新所在连续序列的长度
                m[num] = tmpResult;
                m[num - left] = tmpResult;
                m[num + right] = tmpResult;

                result = max(result, tmpResult);
            }
        }

        return result;
    }
};
