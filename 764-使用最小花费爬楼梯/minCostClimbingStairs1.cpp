#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int length = cost.size();
        if (length == 0) {
            return 0;
        } else if (length == 1) {
            return cost[0];
        }

        /**
         * 至少两级台阶
         * dp[i]表示到达阶梯i所需要的最小花费
         */
        vector<int> dp(length, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < length; ++i) {
            // 爬一个阶梯或者爬两个阶梯到达阶梯i
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // 最后两个阶梯都可以到达楼顶
        return min(dp[length - 1], dp[length - 2]);
    }
};