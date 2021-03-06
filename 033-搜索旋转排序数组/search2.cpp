#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int midNum = nums[mid];
            int lowNum = nums[low];
            int highNum = nums[high];
            if (midNum == target) {
                return mid;
            }
            if (midNum < highNum) { // 右半边有序
                if (target > midNum && target <= highNum) {
                    // target 在[mid + 1 ... high]之间
                    low = mid + 1;
                } else {
                    // target 在[low ... mid - 1]之间
                    high = mid - 1;
                }
            } else { // 左半边有序，此处包含了 low == mid 的情况。
                if (target >= lowNum && target < midNum) {
                    // target 在[low ... mid - 1]之间
                    high = mid - 1;
                } else {
                    // target 在[mid + 1 ... mid]之间
                    low = mid + 1;
                }
            }
        }

        return -1;
    }
};