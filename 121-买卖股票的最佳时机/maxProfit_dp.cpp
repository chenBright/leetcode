#include <vector>
#include <climits>
using namespace std;

// 动态规划
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int minPrice = INT_MAX; // 最小价格
        for (auto it = prices.begin(); it != prices.end(); ++it) {
            if (*it < minPrice) {
                minPrice = *it;
            }
            profit = max(profit, *it - minPrice);
        }
        
        return profit;
    }
};