#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            if (nums[j] != 0) {
                swap(nums[i++], nums[j]);
            }
        }
    }
};
