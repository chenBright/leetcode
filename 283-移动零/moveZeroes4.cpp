#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        int j = 0;
        int len = nums.size();

        while (i < len && j < len) {
            // 将非 0 元素移动到数组前面
            if (nums[j] != 0) {
                nums[i++] = nums[j];
            }
            ++j;
        }

        // 在数组后面补 0
        while (i < len) {
            nums[i] = 0;
        }
    }
};
