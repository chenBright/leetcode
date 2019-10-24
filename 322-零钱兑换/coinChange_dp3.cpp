#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

// 自下而上
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxCount = amount + 1;
        vector<int> dp(amount + 1, maxCount);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const auto& coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
