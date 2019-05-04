#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) {
            return res;
        }

        auto range = equal_range(nums.begin(), nums.end(), target);
        if (range.first == nums.end() || *(range.first) != target) {
            return res;
        }
        res[0] = range.first - nums.begin();
        res[1] = range.second - nums.begin() - 1;

        return res;
    }
};