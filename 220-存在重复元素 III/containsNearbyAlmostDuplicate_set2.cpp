#include <vector>
#include <set>
#include <cmath>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            // 保持滑动窗口的大小为 k
            if (s.size() > k) {
                s.erase(nums[i - k - 1]);
            }

            // 找到第一个大于等于 nums[i] - t 的数
            auto it = s.lower_bound(static_cast<long>(nums[i]) - t);
            // 小于 nums[i] - t 部分肯定不符合条件，只要验证大于等于部分即可
            // 证明：设 x < nums[i] - t，则 -x > nums[i] - t
            // nums[i] - x > nums[i] - nums[i] + t = t
            if (it != s.end() && abs(nums[i] - *it) <= t) {
                return true;
            }

            s.insert(nums[i]);
        }

        return false;
    }
};