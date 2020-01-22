#include <vector>
using namespace std;

// 动态规划
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int sum = 0;
        int result = INT_MIN;
        for (const auto& num : nums) {
            sum += num;
            if (sum > result) {
                result = sum;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return result;
    }
};