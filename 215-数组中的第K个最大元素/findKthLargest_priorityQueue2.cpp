#include <vector>
#include <queue>
#include <functional>
using namespace std;


// 优先队列构建容量为 k 的最小堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int length = nums.size();
        if (nums.empty() || k == 0 || k > length) {
            return -1;
        }

        // 构建容量为 k 的最小堆
        priority_queue<int, vector<int>, greater<int> > q(nums.begin(), nums.begin() + k);

        for (int i = k; i < length; ++i) {
            if (nums[i] > q.top()) {
                q.pop();
                q.push(nums[i]);
            }
        }

        return q.top();
    }
};
