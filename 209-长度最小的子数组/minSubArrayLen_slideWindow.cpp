#include <vector>
using namespace std;

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int minLength = INT_MAX;
        int sum = 0;
        // 滑动窗口
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            sum += nums[right];
            if (sum >= s) {
                while (sum >= s) {
                    minLength = min(minLength, right - left + 1);
                    sum -= nums[left];
                    ++left;
                }
            }
            ++right;
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};
