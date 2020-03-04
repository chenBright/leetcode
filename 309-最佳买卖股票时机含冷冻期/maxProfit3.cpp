#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0;       // 卖出股票
        int hold = INT_MIN; // 持有股票
        int rest = 0;       // 过渡期
        for (int p : prices) {
            int pre_sold = sold;
            // 前一天 hold，当日卖出股票
            sold = hold + p;
            // 前一天 hold，当日 rest
            // 前一天 rest，当日买入股票变为 hold
            hold = max(hold, rest - p);
            // 前一天 sold，当日必须 rest
            // 前一天 rest，当日继续 rest
            rest = max(rest, pre_sold);
        }

        // 最后一天最大值情况为要么什么都不做，要么卖出股票。
        return max(sold, rest);
    }
};
