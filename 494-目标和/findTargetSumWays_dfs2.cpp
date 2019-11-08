#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, S, 0, 0);
    }
private:
    int dfs(vector<int>& nums, int S, int sum, int index) {
        if (index == nums.size()) {
            return sum == S ? 1 : 0;
        }

        return dfs(nums, S, sum + nums[index], index + 1) + dfs(nums, S, sum - nums[index], index + 1);
    }
};
