#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int length = nums.size();
        if (length == 0) {
            return -1;
        }

        int low = 0;
        int high = length - 1;
        int mid;
        while (low < high && high - low > 1) {
            int mid = (low + high) / 2;
            // 不是 mid+(-)1，因为 [mid + 1 ... high]可能是有序数组，即 nums[mid + 1] 是最小值
            if (nums[mid] > nums[low]) { // 左半边有序
                low = mid; 
            } else { // 右半边有序
                high = mid;
            }
        }

        // 先找到最小值点，将数组分成两个有序数组
        int minIndex = nums[low] < nums[high] ? low : high;
        if (minIndex == 0) {
            return binarySearch(nums, 0, length - 1, target);
        } else {
            int leftIndex = binarySearch(nums, 0, minIndex, target);
            int rightIndex = binarySearch(nums, minIndex, length - 1, target);
            return leftIndex != -1 ? leftIndex : rightIndex;
        }
    }

private:
    int binarySearch(vector<int> &nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};