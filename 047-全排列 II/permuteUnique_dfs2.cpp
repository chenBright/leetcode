#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        if (nums.empty()) {
            return result;
        }

        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        permuteUniqueRecursion(nums, 0, visited);

        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmpResult;
    void permuteUniqueRecursion(vector<int> &nums, int level, vector<bool> &visited) {
        if (level == nums.size()) {
            result.push_back(tmpResult);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            if (i != 0 && nums[i] == nums[i - 1] && !visited[i - 1]) { // 去重：该位置上已经有相同的数字了，跳过
                continue;
            }

            visited[i] = true;
            tmpResult.push_back(nums[i]);
            permuteUniqueRecursion(nums, level + 1, visited);
            tmpResult.pop_back();
            visited[i] = false;
        }
    }
};
