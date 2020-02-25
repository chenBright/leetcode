#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        for (int gap = length / 2; gap > 0; gap /= 2) { // 间隔
            for (int i = gap; i < length; ++i) {
                for (int j = i; j - gap >= 0 && nums[j] < nums[j - gap]; j -= gap) {
                    swap(nums[j], nums[j - gap]);
                }
            }
        }

        return nums;
    }
};
