#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int length = nums.size();
        if (nums.empty()) {
            return -1;
        } else if (length == 1) {
            return 0;
        }

        int low = 0;
        int high = length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid == 0) {
                if (nums[mid] > nums[mid + 1]) { // 峰值
                    return mid;
                } else {
                    ++low;
                }
            } else if (mid == length - 1) {
                if (nums[mid] > nums[mid - 1]) { // 峰值
                    return mid;
                } else {
                    --high;
                }
            } else {
                if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) { // 峰值
                    return mid;
                } else if (nums[mid - 1] < nums[mid]) { // 峰值在mid右边
                    low = mid + 1;
                } else {  // 峰值在mid左边
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};