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

        int minNum = nums[0];
        for (int i = 1; i < length; ++i) {
            if (nums[i] < minNum) {
                minNum = nums[i];
            }
        }

        return minNum;
    }
};