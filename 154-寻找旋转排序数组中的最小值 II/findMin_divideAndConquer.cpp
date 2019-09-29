#include <vector>
#include <algorithm>
using namespace std;

// 分治
class Solution {
public:
    int findMin(vector<int> &nums) {
        return helper(nums, 0, static_cast<int>(nums.size()) - 1);
    }
private:
    // 返回 [low ... high] 范围内的最小值
    int helper(vector<int> &nums, int low, int high) {
        if (low == high) {
            return nums[low];
        }
        if (nums[low] < nums[high]) {
            return nums[low];
        }

        int mid = low + (high - low) / 2;

        return min(helper(nums, low, mid), helper(nums, mid + 1, high));
    }
};
