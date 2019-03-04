#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] >= target) {
                break;
            }
            ++i;
        }

        return i;
    }
};