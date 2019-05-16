#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[mid + 1]) { // 保证到最后，nums[low] > nums[low + 1]
                high = mid;
            } else { // 保证到最后，nums[low] < nums[low - 1]
                low = mid + 1;
            }
        }
        return low;
    }
};