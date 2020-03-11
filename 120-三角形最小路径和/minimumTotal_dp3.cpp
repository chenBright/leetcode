#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) {
            return 0;
        }

        int row = triangle.size();
        // 本质上是从下往上走，找出到达顶点的最小路径和。
        // 假设三角形 triangle.size() + 1 层，最后一层结点全为 0。
        // dp[i] 表示到达该层（需要结合循环才知道到达哪一层）第 i + 1 个结点的最小路径和。
        // 每一次都复用 dp 数组，因为计算完本层的最小路径后，下一层的数据已经没有价值，可以直接覆盖。
        vector<int> dp(row + 1, 0);
        for (int i = row - 1; i >= 0; --i) {
            for (int j = 0; j < i + 1; ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};
