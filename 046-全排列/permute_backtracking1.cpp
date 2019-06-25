#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        if (nums.empty()) {
            return result;
        }

        permuteRecursion(nums);

        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmpResult;

    void permuteRecursion(vector<int> &nums) {
        if (nums.empty()) {
            result.push_back(tmpResult);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            vector<int> tmp(nums);
            tmp.erase(tmp.begin() + i);
            tmpResult.push_back(nums[i]);
            permuteRecursion(tmp);
            tmpResult.pop_back();
        }
    }
};