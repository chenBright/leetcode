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
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        // 此时序列为最大，直接翻转整个数组。
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 找到第一对数 nums[j] > nums[i]，即升序结构
        int j = length - 1;
        while (nums[j] <= nums[i]) {
            --j;
        }
        swap(nums[i], nums[j]);

        // 对区域 [i + 1, length - 1] 排序，达到序列最小
        sort(nums.begin() + i + 1, nums.end());
    }
};
