#include <vector>
#include <climits>
using namespace std;

// 分治法
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        return calculateArea(heights, 0, heights.size() - 1);
    }

private:
    int calculateArea(vector<int> &heights, int start, int end) {
        if (start > end) {
            return 0;
        }

        int minIndex = start;
        for (int i = start; i <= end; ++i) {
            if (heights[i] < heights[minIndex]) {
                minIndex = i;
            }
        }

        return max((end - start + 1) * heights[minIndex], 
            max(calculateArea(heights, start, minIndex - 1), calculateArea(heights, minIndex + 1, end)));
    }
};
