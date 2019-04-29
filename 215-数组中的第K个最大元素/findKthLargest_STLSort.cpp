#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
        return a > b;
}

// 先排序，再找出前k大的数字
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        sort(nums.begin(), nums.end(), cmp); // 从大到小排序

        return nums[k - 1];
    }
};