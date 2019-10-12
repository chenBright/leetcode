#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            // 将 nums[i] 放到 nums[nums[i] - 1] 的位置上
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};
