#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        if (nums.empty()) {
            return result;
        }

        permuteUniqueRecursion(nums);

        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmpResult;
    void permuteUniqueRecursion(vector<int> &nums) {
        if (nums.empty()) {
            result.push_back(tmpResult);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) { // 去重：该位置上已经有相同的数字了，跳过
                continue;
            }
            vector<int> tmp(nums);
            tmp.erase(tmp.begin() + i);
            tmpResult.push_back(nums[i]);
            permuteUniqueRecursion(tmp);
            tmpResult.pop_back();
        }
    }
};
