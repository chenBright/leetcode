#include <vector>
using namespace std;

// 动态规划
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int sum = 0;
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > max) {
                max = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return max;
    }
};