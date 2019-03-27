#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int length = nums.size();
        if (nums.empty()) {
            return 0;
        } else if (length == 1) {
            return nums[0];
        }

        /**
         * 至少两件房间
         * dp[i]表示 nums[1 …… i] 所能获得最大收益，可能偷第i间，也可能不偷，还是按照第i-1间的方案偷
         */
        vector<int> dp(length);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < length; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); // 偷第i间 或者 偷第i-1间，不偷第i间
        }

        return dp[length - 1];
    }
};