#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        for (int i = 1; i < length; ++i) {
            for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
                swap(nums[j], nums[j - 1]);
            }
        }

        return nums;
    }
};