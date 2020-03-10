# 695-岛屿的最大面积

## 题目

leetcode：[695-岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)

## DFS

```c++
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
```

## BFS

```c++
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        if (grid.empty()) {
            return 0;
        }

        int maxArea = 0;
        int rowLength = grid.size();
        int colLength = grid[0].size();
        for (int i = 0; i < rowLength; ++i) {
            for (int j = 0; j < colLength; ++j) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int> > q; // <行索引, 列索引>
                    q.push(make_pair(i, j));
                    int count = 0;
                    while (!q.empty()) {
                        auto indexs = q.front();
                        q.pop();
                        int row = indexs.first;
                        int col = indexs.second;
                        // 坐标点会重复加入到队列中，所以需要检查。
                        if (grid[row][col] == 0) {
                            continue;
                        }
                        grid[row][col] = 0;
                        ++count;
                        // 将相邻的土地（1）入队
                        if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                            q.push(make_pair(row - 1, col));
                        }
                        if (row + 1 < rowLength && grid[row + 1][col] == 1) {
                            q.push(make_pair(row + 1, col));
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                            q.push(make_pair(row, col - 1));
                        }
                        if (col + 1 < colLength && grid[row][col + 1] == 1) {
                            q.push(make_pair(row, col + 1));
                        }
                    }
                    maxArea = max(maxArea, count);
                }
            }
        }

        return maxArea;
    }
};
```
