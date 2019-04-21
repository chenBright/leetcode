#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        bool isDouble = false; // 标记 nums[length - 1] == nums[length - 2]
        int length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[length - 1]) { // 不重复的元素
                nums[length++] = nums[i];
                isDouble = false;
            } else {
                if (!isDouble) { // nums[length - 1] != nums[length - 2]
                    nums[length++] = nums[i];
                    isDouble = true;
                }
            }
        }

        return length;
    }
};