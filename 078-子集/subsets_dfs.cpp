#include <vector>
using namespace std;

// BFS 回溯法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmpResult;
        subsetsRecursion(nums, result, tmpResult, 0);

        return result;
    }

private:
    void subsetsRecursion(vector<int>& nums, vector<vector<int>>& result, vector<int>& tmpResult, int index) {
        if (index == nums.size()) {
            result.push_back(tmpResult);
            return;
        }

        // 不取当前数字
        subsetsRecursion(nums, result, tmpResult, index + 1);

        // 取当前数字
        tmpResult.push_back(nums[index]);
        subsetsRecursion(nums, result, tmpResult, index + 1);
        tmpResult.pop_back();
    }
};
