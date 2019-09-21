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

        // i 、j 是索引，所以 i < m，j < n。
        for (int i = 0; i < m; ++i) {
            int previous = dp[0]; // 缓存值，防止被覆盖后得不到值
            for (int j = 0; j < n; ++j) {
                int tmp = dp[j + 1];
                if (t[j] == s[i]) {
                    // 相当于在二维数组中上一个值和斜对角的值相加
                    dp[j + 1] += previous;
                }
                previous = tmp;
            }
        }

        return dp[n];
    }
};
