#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }

        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                high = mid;
            } else { // nums[mid] == nums[high] 时，无法判断收缩的方向，则 --high 再查找
                --high;
            }
        }
        return nums[high];
    }
};
