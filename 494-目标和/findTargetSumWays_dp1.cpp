#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<long, long> > dp(nums.size());
        return dfs(nums, S, 0, dp);
    }
private:
    long dfs(vector<int>& nums, int S, int index, vector<unordered_map<long, long> >& dp) {
        if (index == nums.size()) {
            return S == 0 ? 1 : 0;
        }

        if (dp[index].count(S) != 0) {
            return dp[index][S];
        }

        dp[index][S] = dfs(nums, S - nums[index], index + 1, dp) + dfs(nums, S + nums[index], index + 1, dp);

        return dp[index][S];
    }
};
