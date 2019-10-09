#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int length = nums.size();
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        
        // 找最小值
        for (int i = 1; i < length; ++i) {
            if (nums[i] < nums[i - 1]) {
                minNum = min(minNum, nums[i]);
            }
        }
        
        // 找最大值
        for (int i = length - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                maxNum = max(maxNum, nums[i]);
            }
        }

        int left;
        // 从左往右找第一个大于最小值的值的位置
        for (left = 0; left < length; ++left) {
            if (nums[left] > minNum) {
                break;
            }
        }

        int right;
        // 从右往左找第一个小于最大值的值的位置
        for (right = length - 1; right >= 0; --right) {
            if (nums[right] < maxNum) {
                break;
            }
        }

        return right >= left ? right - left + 1 : 0;
    }
};
