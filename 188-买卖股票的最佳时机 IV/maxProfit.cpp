#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) {
            return 0;
        }

        int length = prices.size();
        if (k >= length / 2) {
            return maxProfitGreedy(prices);
        }

        vector<vector<int> > dp(k, vector<int>{INT_MIN, 0});
        for (const auto& price : prices) {
            dp[0][0] = max(dp[0][0], -price);
            dp[0][1] = max(dp[0][1], dp[0][0] + price);
            for (int i = 1; i < k; ++i) {
                dp[i][0] = max(dp[i][0], dp[i - 1][1] - price);
                dp[i][1] = max(dp[i][1], dp[i][0] + price);
            }
        }

        return dp[k - 1][1];
    }
private:
    int maxProfitGreedy(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT_MIN;
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0) {
                profit += diff;
            }
        }

        return profit;
    }

};
