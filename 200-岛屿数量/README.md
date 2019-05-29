# 200-岛屿数量

## 题目

leetcode：[200-岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)

## DFS

遍历数组，遇到值为"1"，则将其值置为"0"，然后深度优先搜索该位置四周的位置，搜索结束后，记为一个岛屿。

```c++
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
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }

        return count;
    }

private:
    void dfs(vector<vector<char> > &grid, int i, int j) {
        if (grid.empty() || i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0'; // 置0，表示访问过
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};
```

## BFS

使用队列来实现：

遍历数组，遇到值为"1"，则将其值置为"0"，然后宽度优先搜索该位置四周的位置，将值为"1"位置上的值置为"0"，并将该位置加入队列。直到队列为空，搜索结束，记为一个岛屿。

```c++
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
```

