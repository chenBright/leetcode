#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int length = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 和为奇数，则直接返回 false
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        vector<vector<bool> > dp(length, vector<bool>(target + 1, false));

        // 第一行，因为数组元素都是整数，所以 i 从 1 开始。
        for (int i = 1; i < target + 1; ++i) {
            if (nums[0] == i) {
                dp[0][i] = true;
            }
        }

        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < target + 1; --j) {
                dp[i][j] = dp[i - 1][j]; // 如果 j < nums[i]，则 不能 选择 nums[i]
                if (j >= nums[i]) {
                    // 不选择 nums[i] 或者选择 nums[i]
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
            }
        }

        return dp[length - 1][target];
    }
};
