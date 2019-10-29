#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int> > &points) {
        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> m; // <<除数 / 最大公约数, 被除数 / 最大公约数>, 点的个数>
            int duplicate = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate;
                    continue;
                }
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int d = gcb(dx, dy);
                ++m[{dx / d, dy / d}];
            }
            result = max(result, duplicate);
            for (auto it = m.begin(); it != m.end(); ++it) {
                result = max(result, it->second + duplicate);
            }

        }
        return result;
    }

private:
    // 计算最大公约数
    int gcb(int a, int b) {
        return b == 0 ? a : gcb(b, a % b);
    }
};
