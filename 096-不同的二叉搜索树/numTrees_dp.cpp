#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // dp[i]表示i个结点的二叉搜索树的个数
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                // 结点j为根结点时，二叉搜索树的个数
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};