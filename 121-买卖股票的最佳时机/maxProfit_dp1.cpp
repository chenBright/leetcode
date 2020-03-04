#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int dp_0 = INT_MIN; // 持有股票的最大利润
        int dp_1 = 0;       // 没持有股票的最大利润
        for (const auto& price : prices) {
            dp_0 = max(dp_0, -price);
            dp_1 = max(dp_1, dp_0 + price);
        }

        return dp_1;
    }
};
