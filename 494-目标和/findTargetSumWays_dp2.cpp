#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int length = nums.size();
        vector<unordered_map<long, long> > dp(length + 1);

        dp[0][0] = 1;

        for (int i = 0; i < length; ++i) {
            for (const auto& it : dp[i]) {
                int sum = it.first;
                int count = it.second;
                dp[i][sum + nums[i]] += count;
                dp[i][sum - nums[i]] += count; 
            }
        }

        return dp[length][S];
    }
};
