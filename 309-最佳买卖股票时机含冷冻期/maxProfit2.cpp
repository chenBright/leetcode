#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int length = prices.size();
        // dp[i][j]：i 表示第 i + 1 天。
        // j = 0、1、2
        // 0：表示持有股票
        // 1：表示卖出股票
        // 2：表示处于过渡期
        vector<vector<int> > dp(length, vector<int>(3));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i < length; ++i) {
            // 前一天买入股票，当日不操作
            // 前一天过渡期，当日买入股票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            // 前一天买入股票，当日卖出股票
            dp[i][1] = dp[i - 1][0] + prices[i];
            // 前一天过渡期，当日也是过渡期
            // 前一天卖出股票，当日也是过渡期
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }

        // 最后一天最大值情况为要么什么都不做，要么卖出股票。
        return max(dp[length - 1][1], dp[length - 1][2]);
    }
};
