#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int n = obstacleGrid.size(); // 行
        int m = obstacleGrid[0].size(); // 列

        if (m == 0 && n == 0) {
            return 0;
        }

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        return uniquePaths(0, 0, n - 1, m - 1, obstacleGrid);
    }

private:
    int uniquePaths(int i, int j, int maxI, int maxJ, vector<vector<int> > &obstacleGrid) {
        if (i > maxI || j > maxJ || obstacleGrid[i][j] == 1) { // 已经走出网格的最大范围 或者 有障碍物
            return 0;
        } else if (i == maxI && j == maxJ) { // 已经走到终点
            return 1;
        } else if (i == maxI || j == maxJ) { // 已经做到与终点在同一条边上，只剩一条路可以到达终点
            return 1;
        }

        return uniquePaths(i + 1, j, maxI, maxJ, obstacleGrid) + uniquePaths(i, j + 1, maxI, maxJ, obstacleGrid);
    }
};