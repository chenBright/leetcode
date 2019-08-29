#include <vector>
#include <algorithm>
using namespace std;

// 按行求解（超时）
class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        if (height.empty()) {
            return sum;
        }

        auto maxHeightIt = max_element(height.begin(), height.end());
        for (int i = 1; i <= *maxHeightIt; ++i) {
            bool isStart = false; // //标记是否开始更新 tmpSum
            int tmpSum = 0;
            for (int j = 0; j < height.size(); ++j) {
                if (isStart && height[j] < i) {
                    ++tmpSum;
                }
                if (height[j] >= i) {
                    sum += tmpSum;
                    tmpSum = 0;
                    isStart = true;
                }
            }
        }

        return sum;
    }
};