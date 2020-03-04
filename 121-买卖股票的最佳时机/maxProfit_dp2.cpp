#include <vector>
#include <climits>
using namespace std;

// 动态规划
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int minPrice = INT_MAX; // 最小价格
        for (const auto& price : prices) {
            minPrice = min(minPrice, price);
            profit = max(profit, price - minPrice);
        }

        return profit;
    }
};
