#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }

        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};