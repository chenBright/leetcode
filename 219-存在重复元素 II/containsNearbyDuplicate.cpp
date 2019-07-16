#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> m; // <元素, 元素索引>
        for (int i = 0;  i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end()) {
                if (i - m[nums[i]] <= k) {
                    return true;
                }
            }
            m[nums[i]] = i;
        }

        return false;
    }
};