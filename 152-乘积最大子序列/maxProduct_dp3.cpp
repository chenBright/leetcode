#include <vector>
#include <algorithm>
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

        int maxProducttion = INT_MIN;
        int iMax = 1; // 保存最大值
        int iMin = 1; // 保存最小值
        for (int i = 0; i < len; ++i) {
            // 如果数组的数是负数，
            // 那么会导致最大的变最小的，最小的变最大的。
            // 因此交换两个的值。
            if (nums[i] < 0) {
                swap(iMax, iMin);
            }

            // iMax 或 iMin 为 0 时，即前一个数为 0，
            // iMax * nums[i] 不一定是最大值，
            // iMin * nums[i] 不一定是最小值。
            iMax = max(iMax * nums[i], nums[i]);
            iMin = min(iMin * nums[i], nums[i]);

            maxProducttion = max(maxProducttion, iMax);
        }

        return maxProducttion;
    }
};