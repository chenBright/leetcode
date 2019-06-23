#include <vector>
#include <algorithm>
using namespace std;

// 使用 visited 数组记录访问过的元素
class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        if (nums.empty()) {
            return result;
        }

        vector<bool> visited(nums.size(), false);
        permuteRecursion(nums, 0, visited);

        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmpResult;

    void permuteRecursion(vector<int> &nums, int level, vector<bool> &visited) {
        if (level == nums.size()) {
            result.push_back(tmpResult);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            tmpResult.push_back(nums[i]);
            permuteRecursion(nums, level + 1, visited);
            tmpResult.pop_back();
            visited[i] = false;
        }
    }
};