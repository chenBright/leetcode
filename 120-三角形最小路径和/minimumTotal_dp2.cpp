#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) {
            return 0;
        }

        int row = triangle.size();
        // 原地修改，空间复杂度为O(1)，但会破坏了输入。
        // 从下往上走，找出到达顶点的最小路径和。
        for (int i = row - 2; i >= 0; --i) {
            for (int j = 0; j < i + 1; ++j) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};
