#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty()) {
            return result;
        }

        deque<int> q; // 大小等于 k，q[i] 表示从窗口右边家到该元素的最大值。

        for (int i = k - 1; i >= 0; --i) {
            if (q.empty()) {
                q.push_front(nums[i]);
            } else {
                q.push_front(max(nums[i], q.front()));
            }
        }
        result.push_back(q.front());

        
        for (int i = k; i < nums.size(); ++i) {
            q.pop_front();
            auto it = q.begin();
            while ( it != q.end() && *it > nums[i]) {
                 ++it;
            }

            while (it != q.end()) {
                *it++ = nums[i];
            }

            q.push_back(nums[i]);

            result.push_back(q.front());
        }

        return result;
    }
};
