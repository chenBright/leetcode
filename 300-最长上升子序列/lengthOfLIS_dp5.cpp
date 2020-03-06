#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int len = nums.size();
        vector<int> dp;
        for (const auto& num : nums) {
            // 查找第一个不小于 nums[i] 的值
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num);
            } else {
                *it = num;
            }
        }

        // 最后，dp 的长度等于上升序列的长度
        return dp.size();
    }
};
