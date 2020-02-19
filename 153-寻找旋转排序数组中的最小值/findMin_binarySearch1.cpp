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
            // 如果是升序数组，nums[mid] 肯定大于 nums[0]。
            // 在旋转数组中，nums[mid] > nums[low]，表示最小值在 [mid, high] 中。
            // 不是 mid+(-)1，因为 [mid + 1 ... high]可能是有序数组，即 nums[mid + 1] 是最小值
            if (nums[mid] < nums.front()) {
                high = mid;
            } else { // 一定旋转过
                low = mid + 1;
            }
        }

        // 此时，low == high
        return nums[high];
    }
};
