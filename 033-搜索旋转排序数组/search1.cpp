#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        int index = findMin(nums); // 先找出最小值
        // 将数组分成两个有序数组，最后在两个数组中进行二分查找。
        int result = binarySearch(nums, 0, index - 1, target);
        if (result >= 0) {
            return result;
        }

        return binarySearch(nums, index, static_cast<int>(nums.size()) - 1, target);
    }

private:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }

        if (nums.front() < nums.back()) {
            return 0;
        }

        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] < nums[high]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

    int binarySearch(vector<int>& nums, int low, int high, int target) {
        if (low > high) {
            return -1;
        }

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
