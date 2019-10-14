#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
    
        deque<int> q; // q[i] 表示索引，表示窗口内 q[i] 向左到 q[i - 1] 之间的最大值

        for (int i = 0; i < nums.size(); ++i) { 
            if (!q.empty() && q.front() == i - k) {
                q.pop_front();
            }

            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[q.front()]);
            }
        }

        return result;
    }
};
