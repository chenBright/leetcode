#include <vector>
using namespace std;

// 使用选择排序法, k趟找出前k大数字
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        for (int i = 0; i < k; ++i) {
            int max = i;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > nums[max]) {
                    max = j;
                }
            }

            if (max != i) {
                swap(nums[max], nums[i]);
            }
        }

        return nums[k - 1];
    }
};