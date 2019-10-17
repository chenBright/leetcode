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
        // memory[i][j] 记录 从 dungeon[i][j] 到终点至少需要多少健康值。
        vector<vector<int> > memory(row, vector<int>(col, INT_MIN));

        // 健康值不能降为 0，所以还要 - 1
        return -dfs(dungeon, 0, 0, memory) + 1;
        
    }
private:
    int dfs(vector<vector<int> >& dungeon, int rowIndex, int colIndex, vector<vector<int> >& memory) {
        if (rowIndex == dungeon.size() - 1 && colIndex == dungeon[0].size() - 1) {
            return min(dungeon[rowIndex][colIndex], 0);
        }

        if (memory[rowIndex][colIndex] != INT_MIN) {
            return memory[rowIndex][colIndex];
        }

        int result = 0;
        if (rowIndex == dungeon.size() - 1) { // 最后一行
            result = min(dungeon[rowIndex][colIndex] + dfs(dungeon, rowIndex, colIndex + 1, memory), 0);
        } else if (colIndex == dungeon[0].size() - 1) { // 最后一列
            result = min(dungeon[rowIndex][colIndex] + dfs(dungeon, rowIndex + 1, colIndex, memory), 0);
        } else {
            result = max(dfs(dungeon, rowIndex + 1, colIndex, memory), dfs(dungeon, rowIndex, colIndex + 1, memory)); // 展出消耗少的路径
            result = min(dungeon[rowIndex][colIndex] + result, 0);
        }

        memory[rowIndex][colIndex] = result;

        return result;
    }
};
