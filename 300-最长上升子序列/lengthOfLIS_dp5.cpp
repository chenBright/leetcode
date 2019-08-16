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
        for (int i = 0; i < len; ++i) {
            // 查找第一个不小于 nums[i] 的值
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if (it == dp.end()) {
                dp.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        
        // 最后，dp 的长度等于上升序列的长度
        return dp.size();
    }
};
