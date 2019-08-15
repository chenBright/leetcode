#include <vector>
using namespace std;

// 动态规划
class Solution {
public:
    bool canWinNim(int n) {
        // 不用 dp[0]，所以需要 n + 1 个元素
        vector<bool> dp(n + 1, false);
        dp[1] = true;
        dp[2] = true;
        dp[3] = true;

        for (int i = 4; i <= n; ++i) {
            dp[i] = !dp[i - 1] || !dp[i - 2] || !dp[i - 3];
        }

        return dp[n];
    }
};
