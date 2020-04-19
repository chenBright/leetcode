#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// 广度优先搜索
class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }

        // <总数, 个数>
        queue<pair<int, int> > q;
        q.push(make_pair(n, 0));

        // 层序遍历减枝，图可能会反复遍历相同的节点。这里之前遍历过的，后面就不用遍历计算了。
        vector<bool> visited(n + 1, false);
        visited[n] = true;

        while (!q.empty()) {
            int num = q.front().first;
            int count = q.front().second;
            q.pop();
            // 搜索与 num 结点相连的结点，
            // 其中边的权值为不大于完全 num 的平方数，结点为 num - 平方数
            for (int i = 1; i * i <= num; ++i) {
                int sub = num - i * i;
                if (sub < 0) {
                    break;
                } else if (sub == 0) {
                    return count + 1;
                } else {
                    if (!visited[sub]) {
                        q.push(make_pair(sub, count + i));
                        visited[sub] = true;
                    }
                }
            }
        }

        return 0;
    }
};