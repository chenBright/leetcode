#include <vector>
#include <queue>
#include <functional>
using namespace std;


// 使用优先队列找出前k大的数字
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int res = -1;
        if (k == 0 || k > nums.size()) {
            return res;
        }

        priority_queue<int, vector<int>, less<int> > pq(nums.begin(), nums.end());

        // 将前 k - 1 个数出队列
        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }

        return pq.top();
    }
};