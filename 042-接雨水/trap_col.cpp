#include <vector>
#include <algorithm>
using namespace std;

// 按列求解
class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        if (height.empty()) {
            return sum;
        }
        
        for (int i = 1; i < height.size() - 1; ++i) {
            int maxLeft = 0;
            // 找出左边最高
            for (int j = i - 1; j >= 0; --j) {
                maxLeft = max(maxLeft, height[j]);
            }

            int maxRight = 0;
            // 找出右边最高
            for (int k = i + 1; k < height.size(); ++k) {
                maxRight = max(maxRight, height[k]);
            }

            int minHeight = min(maxLeft, maxRight);
            // 只有较小的一段大于当前列的高度才会有水，其他情况不会有水
            if (minHeight > height[i]) {
                sum += minHeight - height[i];
            }
        }

        return sum;
    }
};
