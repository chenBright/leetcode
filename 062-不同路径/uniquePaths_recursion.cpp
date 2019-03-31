class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 && n == 0) {
            return 0;
        }

        return uniquePaths(0, 0, n - 1, m - 1);
    }

private:
    int uniquePaths(int i, int j, int maxI, int maxJ) {
        if (i > maxI || j > maxJ) { // 已经走出网格的最大范围
            return 0;
        } else if (i == maxI && j == maxJ) { // 已经走到终点
            return 1;
        } else if (i == maxI || j == maxJ) { // 已经做到与终点在同一条边上，只剩一条路可以到达终点
            return 1;
        }

        return uniquePaths(i + 1, j, maxI, maxJ) + uniquePaths(i, j + 1, maxI, maxJ);
    }
};