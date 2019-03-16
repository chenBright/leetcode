#include <vector>
using namespace std;

// 蛮力法
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int len = prices.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int diff = prices[j] - prices[i];
                if (diff > profit) {
                    profit = diff;
                }
            }
        }

        return profit;
    }
};