#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

// 蛮力法
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        return lengthOfLIS(nums, INT_MIN, 0);
    }
private:
    int lengthOfLIS(vector<int> &nums, int previous, int currentPositon) {
        if (currentPositon >= nums.size()) {
            return 0;
        }

        int length1 = 0;
        if (nums[currentPositon] > previous) {
            length1 = 1 + lengthOfLIS(nums, nums[currentPositon], currentPositon + 1);
        }

        int length2 = lengthOfLIS(nums, previous, currentPositon + 1);

        return max(length1, length2);
    }
};
