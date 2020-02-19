#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }

        // 数组有序
        // 取等于是考虑到数组只有一个元素的情况
        if (nums.front() <= nums.back()) {
            return nums[0];
        }

        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            // 无论是在升序数组中，还是在旋转数组中，nums[mid] 肯定大于 nums[0]。
            // 也可以与 nums[length - 1] 比较。
            // 此时，nums[mid] < nums[length - 1]，表示最小值肯定不在在 [mid, high] 中。
            if (nums[mid] < nums.back()) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // 此时，low == high
        return nums[low];
    }
};
