#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int> > q; // <nums[i], i>
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.top().second <= i - k) {
                q.pop();
            }

            q.push(make_pair(nums[i], i));

            if (i >= k - 1) {
                result.push_back(q.top().first);
            }
        }
        
        return result;
    }
};
