#include <vector>
#include <algorithm>
using namespace std;


// 使用最小堆找出前 k 大的数字
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        if (nums.empty() || k == 0 || k > nums.size()) {
            return -1;
        }

        make_heap(nums.begin(), nums.end(), less<int>());  // 构造最大堆
        for (int i  = 0; i < k - 1; ++i) {
            pop_heap(nums.begin(), nums.end(), less<int>());
            nums.pop_back();
        }

        return nums[0];
    }
};