#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return -1;
        }

        // 数组有序
        if (nums[0] <= nums[length - 1]) {
            return nums[0];
        }

        int low = 0;
        int high = length - 1;
        int mid;
        while (low < high && high - low > 1) {
            int mid = (low + high) / 2;
            // 不是 mid+(-)1，因为 [mid + 1 ... high]可能是有序数组，即 nums[mid + 1] 是最小值
            if (nums[mid] > nums[low]) {
                low = mid; 
            } else { // 一定旋转过
                high = mid;
            }
        }

        return min(nums[low], nums[high]);
    }
};