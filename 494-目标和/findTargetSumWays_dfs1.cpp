#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int result = 0;
        dfs(nums, S, 0, 0, result);

        return result;
    }
private:
    void dfs(vector<int>& nums, int S, int sum, int index, int& result) {
        if (index == nums.size()) {
            if (sum == S) {
                ++result;
            }

            return;
        }

        dfs(nums, S, sum + nums[index], index + 1, result);
        dfs(nums, S, sum - nums[index], index + 1, result);
    }
};
