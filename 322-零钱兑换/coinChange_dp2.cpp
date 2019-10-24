#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

// 自顶向下
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> count;
        count[0] = 0;
        return coinChange(coins, amount, count);
    }

private:
    int coinChange(vector<int>& coins, int amount, unordered_map<int, int>& count) {
        if (amount < 0) {
            return -1;
        }

        if (count.count(amount) != 0) {
            return count[amount];
        }

        int minCount = INT_MAX;
        // 动态规划的对象是金额数
        // count[i] 表示金额数为 i 时所需的最少硬币个数
        // F(S) = F(S - C) + 1
        for (const auto& coin : coins) {
            int result = coinChange(coins, amount - coin, count);
            if (result >= 0) {
                minCount = min(minCount, result + 1);
            }
        }
        count[amount] = minCount == INT_MAX ? -1 : minCount;
        return count[amount];
    }
};
