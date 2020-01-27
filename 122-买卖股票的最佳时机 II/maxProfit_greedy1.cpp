#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int vally = 0;
        int peak = 0;
        auto it = prices.begin();
        while (it + 1 != prices.end()) {
            // 找到极小值
            while (it + 1 != prices.end() && *it >= *(it + 1)) {
                ++it;
            }
            vally = *it;

            // 找到极大值
            while (it + 1 != prices.end() && *it <= *(it + 1)) {
                ++it;
            }
            peak = *it;

            profit += peak - vally;
        }

        return profit;
    }
};