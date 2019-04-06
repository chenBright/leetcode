#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        if (row == 0) {
            return 0;
        }

        /**
         * 本质上是从下往上走，找出到达顶点的最小路径和
         * 假设三角形 triangle.size() + 1 层，最后一层结点全为0
         * dp[i]表示到达该层（需要结合循环才知道到达哪一层）第 i + 1个结点的最小路径和
         * 每一次都复用dp数组，因为计算完本层的最小路径后，下一层的数据已经没有价值，可以直接覆盖
         */
        vector<int> dp(row + 1, 0);
        for (int i = row - 1; i >= 0; --i) {
            for (int j = 0; j < i + 1; ++j) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};
