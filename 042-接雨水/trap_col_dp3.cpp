#include <vector>
#include <algorithm>
using namespace std;

// 按列求解（动态规划）
class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        int length = height.size();
        int maxLeft = 0;
        int maxRight = 0;
        int left = 1;
        int right = length - 2;
        for (int i = 0; i < length - 1; ++i) {
            if (height[left - 1] < height[right + 1]) { // 从左到右更
                maxLeft = max(maxLeft, height[left - 1]);
                if (maxLeft > height[left]) {
                    sum += maxLeft - height[left];
                }
                ++left;
            } else { // 从右到左更
                maxRight = max(maxRight, height[right + 1]);
                if (maxRight > height[right]) {
                    sum += maxRight - height[right];
                }
                --right;
            }
        }

        return sum;
    }
};