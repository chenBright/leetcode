#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int len = height.size();
        if (len < 2) {
            return 0;
        }

        int left = 0;
        int right = len - 1;
        int maxArea = 0;
        while (left < right) {
            int minHeight = min(height[left], height[right]);
            maxArea = max(maxArea, (right - left) * minHeight);
            // 移动高度小的一边
            if (minHeight == height[left]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxArea;
    }
};