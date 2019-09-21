#include <string>
#include <vector>
using namespace std;

// 行主序
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<long> dp(n + 1, 0);
        // dp[0] 表示空串，因为不管S多长，都只能找到一个空串，与T相等，所以为 1。
        dp[0] = 1; 

        // 当 S = "babgbag", T = "bag"  dp矩阵的变化情况为
        // b: 1 1 0 0
        // a: 1 1 1 0
        // b: 1 2 1 0
        // g: 1 2 1 1
        // b: 1 3 1 1  
        // a: 1 3 4 1  
        // g: 1 3 4 5
        // 
        // i 、j 是索引，所以 i < m，j < n。
        for (int i = 0; i < m; ++i) {
            // 当前 dp 的值相当于二维数组中上一行的值。
            // 从尾开始更新，防止 dp[j + 1] 被覆盖。
            for (int j = n - 1; j >= 0; --j) {
                if (t[j] == s[i]) {
                    // 相当于在二维数组中上一个值和斜对角的值相加
                    dp[j + 1] += dp[j];
                }
            }
        }

        return dp[n];
    }
};
