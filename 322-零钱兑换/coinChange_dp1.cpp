#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

// 自上而下
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount, 0);

        return coinChange(coins, amount, count);
    }

private:
    int coinChange(vector<int>& coins, int amount, vector<int>& count) {
        if (amount < 0) {
            return -1;
        } else if (amount == 0) {
            return 0;
        }
        if (count[amount - 1] != 0) {
            return count[amount - 1];
        }

        int minCount = INT_MAX;
        // 动态规划的对象是金额数
        // count[i] 表示金额数为 i 时所需的最少硬币个数
        // F(S) = F(S - C) + 1
        for (const auto& coin : coins) {
            int result = coinChange(coins, amount - coin, count);
            if (result >= 0 && result < minCount) {
                minCount = result + 1;
            }
        }
        count[amount - 1] = minCount == INT_MAX ? -1 : minCount;
        return count[amount - 1];
    }
};
