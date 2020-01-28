#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT_MAX;
        int length = prices.size();
        for (int i = 0; i + 1 < length; ++i) {
            // 找到极小值
            while (i + 1 < length && prices[i] >= prices[i + 1]) {
                ++i;
            }
            if (i >= length) {
                break;
            }
            minPrice = prices[i];
            ++i;

            // 找到极大值
            while (i + 1 < length && prices[i] <= prices[i + 1]) {
                ++i;
            }
            if (i >= length) {
                break;
            }

            profit += prices[i] - minPrice;
        }

        return profit;
    }
};
