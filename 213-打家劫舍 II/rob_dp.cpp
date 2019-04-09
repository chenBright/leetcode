#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        } else if  (len == 1) {
            return nums[0];
        }

        // 至少有两间房间

        // 偷第一间，不能偷最后一间
        vector<int> dp1(len);
        dp1[0] = dp1[1] = nums[0];

        // 不偷第一间
        vector<int> dp2(len);
        dp2[0] = 0;
        dp2[1] = nums[1];

        for (int i = 2; i < len; ++i) {
            if (i == len - 1) { // 不偷最后一间
                dp1[i] = dp1[i - 1];
            } else {
                dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            }
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }

        return max(dp1[len - 1], dp2[len - 1]);
    }
};