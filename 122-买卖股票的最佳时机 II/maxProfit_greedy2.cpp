#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for (auto it = prices.begin(); it + 1 != prices.end(); ++it) {
            int diff = *(it + 1) - *it;
            // 只要第i天的价格比第i+1天的价格低，则在第i天买入，第i+1天卖出
            if (diff > 0) {
                profit += diff;
            }
        }

        return profit;
    }
};