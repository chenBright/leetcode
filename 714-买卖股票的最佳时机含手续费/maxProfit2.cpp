#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) {
            return 0;
        }

        int dp_0 = 0;           // 不持有股票
        int dp_1 = -prices[0];  // 持有股票
        for (const auto& p : prices) {
            // 前一天不持有股票，当天也不持有股票
            // 前一天持有股票，当天卖出股票股票
            dp_0 = max(dp_0, dp_1 + p - fee);
            // 前一天持有股票，当天也持有股票
            // 前一天不持有股票，当天买入股票股票
            dp_1 = max(dp_1, dp_0 - p);
        }

        return dp_0;
    }
};