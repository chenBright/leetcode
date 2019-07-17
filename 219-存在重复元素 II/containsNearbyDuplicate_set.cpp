#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        set<int> s; // 滑动窗口 <元素>
        for (int i = 0;  i < nums.size(); ++i) {
            // 保持滑动窗口的大小为 k
            if (s.size() > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }

        return false;
    }
};