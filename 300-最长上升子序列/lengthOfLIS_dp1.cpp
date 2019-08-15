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
        // dp[i] 表示以 nums[i] 为序列的第一个数字的最长子序列的长度
        vector<int> dp(len, 1);
        int maxLength = 1;
        for (int i = len - 1; i >= 0; --i) {
            int tmpLength = 1;
            // nums[i] 与以 nums[j]（j = i + 1 ... nums.size() - 1）为起点的子序列能否组成上升序列
            for (int j = i + 1; j < len; ++j) {
                if (nums[i] < nums[j]) {
                    // 如果能，则 dp[i] = 1 + dp[j]
                    tmpLength = max(tmpLength, 1 + dp[j]);
                }
            }
            dp[i] = max(dp[i], tmpLength);
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
