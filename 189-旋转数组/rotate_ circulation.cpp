#include <vector>
#include <algorithm>
using namespace std;

// 循环移动
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int length = nums.size();
        if (length == 0 || length == 1) {
            return;
        }

        // 当k大于数组长度时，取余
        if (k > length) {
            k = k % length;
        }

        int temp;
        for (int i = 0; i < k; ++i) {
            temp = nums[length - 1]; // 暂存最后一个元素
            for (int j = length - 1; j > 0; --j) {
                nums[j] = nums[j - 1];
            }
            nums[0] = temp; // 移动最后一个元素
        }
    }
};