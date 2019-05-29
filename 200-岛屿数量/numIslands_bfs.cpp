#include <vector>
#include <queue>
using namespace std;

// BFS
class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        if (grid.empty()) {
            return 0;
        }

        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++count;
                }
            }
        }

        return count;
    }

private:
    void bfs(vector<vector<char> > &grid, int i, int j) {
        if (grid.empty() || i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        grid[i][j] = '0'; // 置0，表示访问过
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            int x = pos.first;
            int y = pos.second;
            if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                grid[x - 1][y] = '0';
                q.push(make_pair(x - 1, y));
            }
            if (x + 1 < grid.size() && grid[x + 1][y] == '1') {
                grid[x + 1][y] = '0';
                q.push(make_pair(x + 1, y));
            }
            if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                grid[x][y - 1] = '0';
                q.push(make_pair(x, y - 1));
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] == '1') {
                grid[x][y + 1] = '0';
                q.push(make_pair(x, y + 1));
            }
        }
    }
};