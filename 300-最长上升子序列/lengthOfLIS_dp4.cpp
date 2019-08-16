#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int len = nums.size();
        vector<int> dp;
        for (int i = 0; i < len; ++i) {
            // 查找第一个不小于 nums[i] 的值
            int low = 0;
            int high = dp.size();
            while (low < high) {
                int mid = (low + high) / 2;
                if (dp[mid] < nums[i]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }

            // 如果查找失败，则将 nums[i] 添加到 dp 数组末尾；
            // 如果查找成功，则用 nums[i] 替换它。
            if (high >= dp.size()) {
                dp.push_back(nums[i]);
            } else {
                dp[high] = nums[i];;
            }
        }
        
        // 最后，dp 的长度等于上升序列的长度
        return dp.size();
    }
};
