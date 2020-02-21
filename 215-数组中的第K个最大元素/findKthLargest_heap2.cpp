#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


// 构建容量为 k 的最小堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int length = nums.size();
        if (nums.empty() || k == 0 || k > length) {
            return -1;
        }

        make_heap(nums.begin(), nums.begin() + k, greater<int>());

        for (int i = k; i < length; ++i) {
            if (nums[i] > nums[0]) {
                swap(nums[i], nums[0]);
                make_heap(nums.begin(), nums.begin() + k, greater<int>());
            }
        }

        return nums[0];
    }
};
