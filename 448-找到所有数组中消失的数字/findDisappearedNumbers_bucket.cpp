#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            // 将 nums[i] 放到 nums[nums[i] - 1] 的位置上
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        vector<int> result;
        for (int j = 0; j < length; ++j) {
            if (nums[j] != j + 1) {
                result.push_back(j + 1);
            }
        }

        return result;
    }
};
