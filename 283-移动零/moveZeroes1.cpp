#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        int j = 0;
        int len = nums.size();
        while (i < len && j < len) {
            // 找 0 元素
            while (i < len && nums[i] != 0) {
                ++i;
            }

            // 找非 0 元素
            j = i + 1;
            while (j < len && nums[j] == 0) {
                ++j;
            }

            // 交换
            if (i < len && j < len) {
                swap(nums[i++], nums[j]);
            }
        }
    }
};
