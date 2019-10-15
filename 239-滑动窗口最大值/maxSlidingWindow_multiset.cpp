#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        multiset<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                s.erase(s.find(nums[i - k]));
            }
            s.insert(nums[i]);
            if (i >= k - 1) {
                result.push_back(*s.rbegin());
            }
        }

        return result;
    }
};
