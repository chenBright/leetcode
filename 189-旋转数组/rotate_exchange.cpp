#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int length = nums.size();
        if (length == 0 || length == 1) {
            return;
        }

        if (k > length) {
            k = k % length;
        }

        int base = 0;
        int place = (base + k) % length;
        for (int i = 0; i < length; ++i) {
            swap(nums[base], nums[place]);
            place = (place + k) % length;
            // 被交换到base位置上的元素的最终位置就是base，则移动base位置、跳过该元素、更新place
            if (base == place) {
                ++base; // 移动base位置
                ++i; // 跳过该元素
                place = (base + k) % length; // 更新place
            }
        }
    }
};