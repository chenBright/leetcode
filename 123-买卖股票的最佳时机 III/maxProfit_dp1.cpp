#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        if (prices.empty()) {
            return profit;
        }

        int len = prices.size();
        int minPrice = prices[0];           // 当前可买入时的最小价格
        int maxPrice = prices[len - 1];     // 当前可卖出的最小价格
        vector<int> leftMaxProfit(len, 0);  // 到i天的左边最大利润
        vector<int> rightMaxProfit(len, 0); // i天之后右边的最大利润
        // 动态规划 第i天之前的最大收入
        for (int i = 1; i < len; ++i) {
            minPrice = min(minPrice, prices[i]);
            leftMaxProfit[i] = max(leftMaxProfit[i - 1], prices[i] - minPrice);
        }
        // 动态规划 第i天之后的最大收入
        for (int j = len - 2; j >= 0; --j) {
            maxPrice = max(maxPrice, prices[j]);
            rightMaxProfit[j] = max(rightMaxProfit[j + 1], maxPrice - prices[j]);
        }
        // 计算左、右和的最大利润
        for (int k = 0; k < len; ++k) {
            profit = max(leftMaxProfit[k] + rightMaxProfit[k], profit);
        }

        return profit;
    }
};
