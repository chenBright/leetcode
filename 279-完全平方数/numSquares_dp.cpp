#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// 动态规划
class Solution {
public:
    int numSquares(int n) {
        /**
         * dp[i]表示凑成 i 需要的最少平方和
         * dp(n) = 1 + min{ dp(n-1^2), dp(n-2^2), dp(n-3^2), dp(n-4^2), ... , dp(n-k^2) }，
         * 其中 k 为满足 k^2 <= n 的最大的 k
         * 其中 1 实则为 k^2 的个数
         */
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int sq = static_cast<int>(sqrt(i));
            int minCount = i;
            for (int j = 1; j <= sq; ++j) {
                minCount = min(minCount, dp[i - j * j]);
            }
            dp[i] = minCount + 1;
        }

        return dp[n];
    }
};