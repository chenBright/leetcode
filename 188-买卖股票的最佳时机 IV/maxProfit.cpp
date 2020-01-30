#include <vector>
using namespace std;

/**
 * 1. 当k大于等于数组长度一半时,
 * 问题退化为贪心问题此时采用 122-买卖股票的最佳时机 II 的方法。
 *
 * 2. 当k不大于数组长度一半时，
 * 可以使用 123-买卖股票的最佳时机 III 的方法来解决，
 * 将两笔买卖的变量扩展成长度为 k 的二维数组，即 123 题中的 k = 2。
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) {
            return 0;
        }

        int len = prices.size();
        if (k >= len / 2) {
            return maxProfit_greedy(prices);
        }

        int profit = 0;
        vector<pair<int, int> > deals(k, make_pair(INT_MIN, 0));
        for (int p : prices) {
            deals[0].first = max(deals[0].first, -p);
            deals[0].second = max(deals[0].second, deals[0].first + p);
            for (int i = 1; i < k; ++i) {
                deals[i].first = max(deals[i].first, deals[i - 1].second - p);
                deals[i].second = max(deals[i].second, deals[i].first + p);
            }
        }

        return deals[k - 1].second;
    }

private:
    int maxProfit_greedy(vector<int> &prices) {
        int profit = 0;
        for (int i = 0; i + 1 < prices.size(); ++i) {
            int diff = prices[i + 1] - prices[i];
            // 只要第 i 天的价格比第 i+1 天的价格低，则在第 i 天买入，第 i+1 天卖出
            if (diff > 0) {
                profit += diff;
            }
        }

        return profit;
    }
};