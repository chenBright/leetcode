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
        while (low <= high) {
            int mid = (low + high) / 2;
            int midNum = nums[mid];
            int lowNum = nums[low];
            int highNum = nums[high];
            if (midNum == target) {
                return mid;
            }
            if (midNum >= lowNum) { // 左半边有序
                if (target >= lowNum && target < midNum) { // target 在[low ... mid - 1]之间
                    high = mid - 1;
                } else { // target 在[mid + 1 ... mid]之间
                    low = mid + 1;
                }
            } else { // 右半边有序
                if (target > midNum && target <= highNum) { // target 在[mid + 1 ... high]之间
                    low = mid + 1;
                } else { // target 在[low ... mid - 1]之间
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};