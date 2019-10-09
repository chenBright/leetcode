#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int length = nums.size();
        int left = length;
        int right = 0;
        vector<int> snums(nums);
        sort(snums.begin(), snums.end());
        for (int i = 0; i < length; ++i) {
            if (nums[i] != snums[i]) {
                left = min(left, i);
                right = max(right, i);
            }
        }

        return right >= left ? right - left + 1 : 0;
    }
};
