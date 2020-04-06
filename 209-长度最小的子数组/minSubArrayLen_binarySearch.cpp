#include <vector>
using namespace std;

// 滑动窗口 + 二分搜索
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int length = nums.size();
        if (length == 0 || s <= 0) {
            return 0;
        }

        int minWindow = 0; // 最小窗口宽度
        int left = 0;
        int right = length;
        while (left <= right) {
            int mid = (left + right) / 2; // 滑动窗口大小
            if (isSub(mid, s, nums)) { // mid 大的滑动窗口符合条件，则缩小窗口大小，继续搜索
                minWindow = mid;
                right = mid - 1;
            } else { // mid 大的滑动窗口不符合条件，则扩大窗口大小，继续搜索
                left = mid + 1;
            }
        }

        return minWindow;
    }

private:
    bool isSub(int size, int target, vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (i >= size) { // 限制窗口最大为 size
                sum -= nums[i - size];
            }
            if (sum >= target) {
                return true;
            }
        }

        return false;
    }
};