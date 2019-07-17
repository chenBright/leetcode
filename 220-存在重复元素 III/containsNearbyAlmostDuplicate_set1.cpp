#include <vector>
#include <set>
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

            auto lowerIt = maxLower(s, nums[i]);
            // 找到小于等于 tarnums[i] 的最大的数，且 nums[i] - 该数 <= t，则符合条件
            if (lowerIt != s.end() && nums[i] - *lowerIt <= t) {
                return true;
            }

            auto upperIt = minUpper(s, nums[i]);
            // 找到大于等于 tarnums[i] 的最小的数，且 该数 - nums[i] <= t，则符合条件
            if (upperIt != s.end() && *upperIt - nums[i] <= t) {
                return true;
            }

            s.insert(nums[i]);
        }

        return false;
    }

private:
    // 找到小于等于 target 的最大的数
    set<long>::iterator maxLower(set<long> &s, int target) {
        if (s.empty()) {
            return s.end();
        }

        auto it = s.lower_bound(target);
        if (it == s.begin()) {
            if (*it == target) { // 第一个元素等于 target，则返回 begin()
                return it;
            } else { // 没有小于等于 target 的数，则返回 end()
                return s.end();
            }
        }

        // 前一个迭代器才是指向小于等于 target 的最大的数
        return --it;
    }

    // 找到大于等于 target 的最小的数
    set<long>::iterator minUpper(set<long> &s, int target) {
        if (s.empty()) {
            return s.end();
        }

        auto it = s.upper_bound(target);
        if (it == s.begin()) {
            return it;
        }

        // 如果前一个迭代器指向的数字等于 target，则指向前一个
        if (*--it != target) {
            ++it;
        }

        return it;
    }
};