#include <vector>
#include <algorithm>
using namespace std;

// 选择排序
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int length = nums.size();
        int left = length;
        int right = 0;
        for (int i = 0; i < length - 1; ++i) {
            for (int j = i + 1; j < length; ++j) {
                if (nums[j] < nums[i]) {
                    left = min(left, i);
                    right = max(right, j);
                }
            }
        }

        return right >= left ? right - left + 1 : 0;
    }
};
