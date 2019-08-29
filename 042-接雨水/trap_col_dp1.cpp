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
        vector<int> maxLefts(length);
        for (int i = 1; i < length; ++i) {
            maxLefts[i] = max(maxLefts[i - 1], height[i - 1]);
        }

        vector<int> maxRights(length);
        for (int j = length - 2; j >= 0; --j) {
            maxRights[j] = max(maxRights[j + 1], height[j + 1]);
        }
        
        for (int k = 1; k < height.size() - 1; ++k) {
            int minHeight = min(maxLefts[k], maxRights[k]);
            // 只有较小的一段大于当前列的高度才会有水，其他情况不会有水
            if (minHeight > height[k]) {
                sum += minHeight - height[k];
            }
        }

        return sum;
    }
};