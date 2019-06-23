#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        if (nums.empty()) {
            return result;
        }

        permuteRecursion(nums, 0);

        return result;
    }

private:
    vector<vector<int> > result;

    void permuteRecursion(vector<int> &nums, int start) {
        if (start >= nums.size()) {
            result.push_back(nums);
        }

        for (int i = start; i < nums.size(); ++i) {
            // 是后面的数字都在 start 位置上排一次
            swap(nums[start], nums[i]);
            permuteRecursion(nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
};
