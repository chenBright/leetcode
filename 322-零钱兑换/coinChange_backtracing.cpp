#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int result = INT_MAX;
        int tmpResult = 0;
        coinChange(coins, 0, amount, tmpResult, result);

        return result == INT_MAX ? result : -1;
    }

private:
    void coinChange(vector<int>& coins, int index, int amount, int& tmpResult, int& result) {
        if (amount == 0) {
            result = min(result, tmpResult);
            return;
        }

        if (index == coins.size()) {
            return;
        }

        for (int i = 0; i <= amount / coins[index]; ++i) {
            tmpResult += i;
            coinChange(coins, index + 1, amount - i * coins[index], tmpResult, result);
            tmpResult -= i;
        }
    }
};
