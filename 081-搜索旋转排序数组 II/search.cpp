#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int midNum = nums[mid];
            int lowNum = nums[low];
            int highNum = nums[high];
            if (target == midNum) {
                return true;
            }

            if (midNum < highNum) { // 右半边有序
                if (midNum <= target && target <= highNum) { // target 在[mid + 1 ... high]之间
                    low = mid + 1;
                } else { // target 在[low ... mid - 1]之间
                    high = mid - 1;
                }
            } else if (midNum > highNum) { // 左半边有序
                if (lowNum <= target && target <= midNum) { // target 在[low ... mid - 1]之间
                    high = mid - 1;
                } else { // target 在[mid + 1 ... mid]之间
                    low = mid + 1;
                }
            } else { // midNum == highNum，无法判断是否有序，例如 [1, 3, 1, 1, 1]
                --high;
            }
        }

        return false;
    }
};