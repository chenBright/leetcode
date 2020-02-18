#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            int num = abs(nums[i]);
            if (nums[num - 1] > 0) {
                nums[num - 1] *= -1;
            }
        }

        vector<int> result;
        for (int j = 0; j < length; ++j) {
            if (nums[j] > 0) {
                result.push_back(j + 1);
            }
        }

        return result;
    }
};
