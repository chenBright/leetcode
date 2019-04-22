#include <vector>
using namespace std;

// 滑动窗口
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int length = nums.size();
        if (length == 0 || s <= 0) {
            return 0;
        }

        int minWindow = 0; // 最小窗口宽度
        int left = 0; // 窗口左边
        int right = 0; // 窗口右边
        int sum = nums[0]; // 窗口和
        while (left < length && right < length) {
            if (sum >= s) { // 满足条件
                int width = right - left + 1;
                minWindow = minWindow == 0 ? width : min(minWindow, width); // 设定最小窗口宽度
                // 减小窗口
                sum -= nums[left];
                ++left;
            } else { // 不满足，则扩大窗口
                ++right;
                if (right >= length) {
                    break;
                }
                sum += nums[right];
            }
        }

        return minWindow;
    }
};