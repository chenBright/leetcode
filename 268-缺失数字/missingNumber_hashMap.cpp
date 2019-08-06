#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        vector<bool> m(nums.size() + 1, false); // 记录 0 ... n 的数字是否出现
        for (const auto &num : nums) {
            m[num] = true;
        }

        for (int i = 0; i < m.size(); ++i) {
            if (!m[i]) {
                return i;
            }
        }

        return -1; // 未缺失任何数字（保证函数有返回值）
    }
};
