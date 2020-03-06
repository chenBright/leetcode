#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int length = nums.size();
        vector<int> dp(length, 1);
        int maxLength = 1;
        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
