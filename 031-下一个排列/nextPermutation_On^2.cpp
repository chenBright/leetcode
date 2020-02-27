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

        for (int i = length - 2; i >= 0; --i) {
            for (int j = length - 1; j > i; --j) {
                if (nums[j] > nums[i]) {
                    // 找到第一对数 nums[j] > nums[i]，即升序结构
                    swap(nums[j], nums[i]); // 交换
                    // 对[i + 1 ... length - 1]排序，达到最小
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }

        // 数组降序，改成升序
        reverse(nums.begin(), nums.end());
    }
};
