#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


// 使用最小堆找出前k大的数字
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        make_heap(nums.begin(), nums.end(), less<int>());  // 构造最大堆
        for (int i  = 0; i < k - 1; ++i) {
            pop_heap(nums.begin(), nums.end(), less<int>());
            nums.pop_back();
        }

        return nums[0];
    }
};