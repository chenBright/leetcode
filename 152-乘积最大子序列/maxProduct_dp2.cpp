#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return nums[0];
        }

        vector<int> leftDp(nums.begin(), nums.end());
        // 将数组逆置，这样就可以和leftDp写在同一个循环中，实现从右到左计算
        vector<int> rightDp(nums.rbegin(), nums.rend());

        for (int i = 1; i < len; ++i) {
            // 前一个数为0，则乘1
            leftDp[i] *= leftDp[i - 1] == 0 ? 1 : leftDp[i - 1]; // 从左到右计算
            rightDp[i] *= rightDp[i - 1] == 0 ? 1 : rightDp[i - 1]; // 从右到左计算
        }

        int maxProduction = INT_MIN;
        for (int j = 0; j < len; ++j) {
            maxProduction = max(leftDp[j], maxProduction);
            maxProduction = max(rightDp[j], maxProduction);
        }

        return maxProduction;
    }
};
