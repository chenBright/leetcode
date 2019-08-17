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
        vector<int> dp{nums[0]};
        for (int i = 0; i < len; ++i) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]); // 符合上升序列的要求
            } else {
                // 查找第一个不小于 nums[i] 的值，并用 nums[i] 替换它
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
                dp[high] = nums[i];
            }
        }
        
        // 最后，dp 的长度等于上升序列的长度
        return dp.size();
    }
};
