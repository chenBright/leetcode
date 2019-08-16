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
        vector<int> dp(len, 1);
        int maxLength = 1;
        for (int i = 1; i < len; ++i) {
            int tmpLength = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    tmpLength = max(tmpLength, 1 + dp[j]);
                }
            }
            dp[i] = tmpLength;
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
