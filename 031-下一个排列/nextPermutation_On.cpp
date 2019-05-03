#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int length = nums.size();
        if (length == 0 || length == 1) {
            return;
        }

        int i = length - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            --i;
        }

        if (i >= 0) {
            int j = length - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        for (int start = i + 1, end = length - 1; start < end; ++start, --end) {
            swap(nums[start], nums[end]);
        }
    }
};