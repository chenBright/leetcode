#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return -1;
        }

        for (int i = 1; i < length; ++i) {
            if (nums[i] < nums[i - 1]) {
                return nums[i];
            }
        }

        return nums[0];
    }
};