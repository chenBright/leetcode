#include <vector>
#include <algorithm>
using namespace std;

// 按列求解（动态规划）
class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        if (height.empty()) {
            return sum;
        }

        int length = height.size();
        vector<int> maxRights(length);
        for (int i = length - 2; i >= 0; --i) {
            maxRights[i] = max(maxRights[i + 1], height[i + 1]);
        }
        
        int maxLeft = 0;
        for (int j = 1; j < height.size() - 1; ++j) {
            maxLeft = max(maxLeft, height[j - 1]);
            int minHeight = min(maxLeft, maxRights[j]);
            // 只有较小的一段大于当前列的高度才会有水，其他情况不会有水
            if (minHeight > height[j]) {
                sum += minHeight - height[j];
            }
        }

        return sum;
    }
};