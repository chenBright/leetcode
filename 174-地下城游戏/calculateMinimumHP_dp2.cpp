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
        vector<int> dp(col + 1, INT_MIN);
        // dp[col] = INT_MIN，表示永远不会选择会越界的路径
        dp[col - 1] = 0;

        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                int minPath = max(dp[j], dp[j + 1]);
                dp[j] = min(minPath + dungeon[i][j], 0);
            }
        }

        // 健康值不能降为 0，所以还要 - 1
        return -dp[0] + 1;
    }
};
