#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int len = nums.size();
        if (len < 3) {
            return -1;
        }

        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < len; ++i) {
            int j = i + 1;
            int k = len - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(closestSum - target) > abs(sum - target)) {
                    closestSum = sum;
                }
                if (sum == target) {
                    return closestSum;
                } else if (sum < target) {
                    ++j;
                } else {
                    --k;
                }
            }
        }

        return closestSum;
    }
};