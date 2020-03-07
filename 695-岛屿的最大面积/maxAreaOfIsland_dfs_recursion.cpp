#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        if (grid.empty()) {
            return 0;
        }

        int area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    area = max(area, dfs(grid, i, j));
                }
            }
        }

        return area;
    }
private:
    int dfs(vector<vector<int> >& grid, int i, int j) {
        if (i < 0 || i == grid.size()) {
            return 0;
        } else if (j < 0 || j == grid[0].size()) {
            return 0;
        }

        if (grid[i][j] == 1) {
            grid[i][j] = 0;
            return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
        }

        return 0;
    }
};