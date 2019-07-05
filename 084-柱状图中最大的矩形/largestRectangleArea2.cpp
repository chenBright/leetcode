#include <vector>
#include <climits>
using namespace std;

// 蛮力法
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int len = heights.size();
        int result = 0;
        for (int i =0; i < len; ++i) {
            int minHeight = heights[i];
            for (int j = i; j < len; ++j) {
                minHeight = min(minHeight, heights[j]);
                result = max(result, (j - i + 1) * minHeight);
            }
        }

        return result;
    }
};
