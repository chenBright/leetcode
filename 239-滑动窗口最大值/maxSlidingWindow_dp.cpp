#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int length = nums.size();
        if (length * k == 0) {
            return vector<int>();
        } else if (k == 1) {
            return nums;
        }

        vector<int> left(length, 0);
        left[0] = nums[0];

        vector<int> right(length, 0);
        right[length - 1] = nums[length - 1];

        // 左 -> 右
        for (int i = 1; i < length; ++i) {
            if (i % k == 0) { // 块的左边界
                left[i] = nums[i];
            } else {
                left[i] = max(left[i - 1], nums[i]);
            }
        }

        // 右 -> 左
        for (int j = length - 2; j >= 0; --j) {
            if ((j + 1) % k == 0) {
                right[j] = nums[j];
            } else {
                right[j] = max(right[j + 1], nums[j]);
            }
        }

        vector<int> result(length - k + 1);
        for (int i = 0; i < length - k + 1; ++i) {
            // i 表示滑动窗口的左边界
            result[i] = max(right[i], left[i + k - 1]);
        }

        return result;
    }
};
