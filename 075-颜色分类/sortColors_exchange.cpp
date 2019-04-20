#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int length = nums.size();
        int low = 0;
        int high = length - 1;
        int i = 0;
        /**
         * [0...low - 1]为小于 1 的数，即0
         * [low...i]为等于 1 的数
         * [i...high]为不确定大小的数
         * [high...nums.size() - 1]为大于 1 的数，即2
         */
        while (i <= high) {
            if (nums[i] < 1) {
                swap(nums[low++], nums[i++]);
            } else if (nums[i] > 1) {
                swap(nums[i], nums[high--]);
            } else {
                ++i;
            }
        }
    }
};