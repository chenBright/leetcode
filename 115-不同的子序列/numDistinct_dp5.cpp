#include <string>
#include <vector>
using namespace std;

// 行主序 + 字典
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<long> dp(n + 1, 0);
        // dp[0] 表示空串，因为不管S多长，都只能找到一个空串，与T相等，所以为 1。
        dp[0] = 1; 

        // 构造 t 的字典，当 s[i] == t[j] 时，通过 next 数组访问下一个
        vector<int> hash(128, -1);
        vector<int> next(n, -1);
        for (int i = 0; i < n; ++i) {
            int c = t[i];
            // next 存放字符 c （在 t 中）之前的位置，然后再更新 hash 的位置
            next[i] = hash[c];
            hash[c] = i;
        }

        // 当S = "babgbag", T = "baga" 时，
        // next数组为 -1  -1  -1  1  
        // （-1 表示之前在 t 中的位置为 -1，即该位置为字母第一次出现的位置。而最后一次出现的位置存储在 hash 中）
        // （遍历的时候，从后往前遍历，一直遍历到 -1 位置）
        // hash[a] = 3   hash[b] = 0   hash[g] = 2 
        // dp矩阵的变化情况为
        // b: 1 1 0 0 0 
        // a: 1 1 1 0 0  
        // b: 1 2 1 0 0
        // g: 1 2 1 1 0
        // b: 1 3 1 1 0  
        // a: 1 3 4 1 1
        // g: 1 3 4 5 1
        for (int i = 0; i < m; ++i) {
            // 降低当前 for 的时间复杂度。
            // 观察前几种动态规划解法 3、4，内循环都是在找 t[i] == s[i]。
            // 而此部分信息，已经存储在 next 中。
            for (int j = hash[s[i]]; j >= 0; j = next[j]) {
                dp[j + 1] += dp[j];
            }
        }

        return dp[n];
    }
};
