#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if (dungeon.empty()) {
            return 0;
        }

        int row = dungeon.size();
        int col = dungeon[0].size();
        // dp[i][j] 表示从 dungeon[i][j] 到终点至少需要多少健康值。
        vector<vector<int> > dp(row + 1, vector<int>(col + 1, INT_MIN));
        dp[row - 1][col] = 0;
        dp[row][col - 1] = 0;

        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                int minPath = max(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = min(minPath + dungeon[i][j], 0);
            }
        }

        // 健康值不能降为 0，所以还要 - 1
        return -dp[0][0] + 1;
    }
};
