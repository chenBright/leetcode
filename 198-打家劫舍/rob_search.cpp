#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        memo.resize(nums.size(), -1);
        return tryRob(nums, 0);
    }

private:
    vector<int> memo;
    int tryRob(vector<int> &nums, int index) {
        int length = nums.size();
        if (index >= length) {
            return 0;
        }

        // 记忆化搜索可以避免重叠子问题的重复运算
        if (memo[index] != -1) {
            return memo[index];
        }

        int res = 0;
        for (int i = index; i < length; ++i) {
            res = max(res, nums[i] + tryRob(nums, i + 2));
        }
        memo[index] = res;

        return res;
    }
};