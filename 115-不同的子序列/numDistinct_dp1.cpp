#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        // dp[0][j] 与 dp[i][0] 表示空串
        // dp[i, j] 表示 s[0 ... i] 与 t[0 ... j] 的匹配个数
        vector<vector<long> > dp(m + 1, vector<long>(n + 1, 0));

        // 如果 s 为空串，则一定是 t 的子序列
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }

        // 如果 t 为空串，（除了 s 也为 空串）不是 s 的空串。
        // 所以初始化为 0。（在 dp 创建的时候已完成初始化为 0 的工作）

        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                // dp[i - 1][j] 表示 s[0 ... i - 1] 与 t[0 ... j] 的匹配个数。
                // dp[i - 1][j - 1] 表示 s[0 ... i - 1] 与 t[0 ... j - 1] 的匹配个数。
                // 如果 s[i - 1] == t[j - 1]，则在 s[0 ... i - 1] 与 t[0 ... j - 1] 的匹配子序列后
                // 增加 s[i]（t[j]），也是匹配的，所以要加 dp[i - 1][j - 1]。
                dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }

        return dp[m][n];
    }
};
