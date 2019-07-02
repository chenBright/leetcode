#include<vector>
using namespace std;

// LeetCode 官方答案
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        
        int prevdiff = nums[1] - nums[0];
        int result = prevdiff != 0 ? 2 : 1;
        for (int i = 2; i < len; ++i) {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
                ++result;
                prevdiff = diff;
            }
        }

        return result;
    }
};