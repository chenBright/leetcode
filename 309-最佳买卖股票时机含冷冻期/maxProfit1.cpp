#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp_0 = INT_MIN; // 代表 dp[i][0]，表示当前持有股票
        int dp_1 = 0;       // 代表 dp[i][1]，表示当前没有持有股票
        int dp_pre_1 = 0;   // 代表 dp[i-2][1]，表示上一次卖出股票

        for (const auto& price : prices) {
            // 前一天没有持有股票，当日也没有持有股票，没有操作
            // 前一天持有股票，当日卖出股票
            dp_0 = max(dp_0, dp_pre_1 - price);
            dp_pre_1 = dp_1;
            // 前一天持有股票，当日也持有股票，没有操作
            // 上一次卖出股票，前一天没有操作，当日买入股票
            dp_1 = max(dp_1, dp_0 + price);
        }

        return dp_1;
    }
};