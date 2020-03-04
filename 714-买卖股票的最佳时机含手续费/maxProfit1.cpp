#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) {
            return 0;
        }

        int length = prices.size();
        // dp[i] 表示第 i + 1 天，对应 prices[i]
        // 0: 持有股票
        // 1: 不持有股票
        vector<vector<int> > dp(length, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < length; ++i) {
            // 前一天持有股票，当天也持有股票
            // 前一天不持有股票，当天买入股票股票
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // 前一天不持有股票，当天也不持有股票
            // 前一天持有股票，当天卖出股票股票
            dp[i][1] = max(dp[i - 1][1], dp[i][0] + prices[i]- fee);
        }

        return dp[length - 1][1];
    }
};
