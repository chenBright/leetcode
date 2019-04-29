#include <vector>
using namespace std;

// 冒泡排序
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        for (int i = 0; i < k; ++i) {
            for (int j = nums.size() - 1; j > i; --j) {
                if (nums[j] > nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                }
            }
        }

        return nums[k - 1];
    }
};