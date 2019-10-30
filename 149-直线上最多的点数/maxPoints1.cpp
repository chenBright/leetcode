#include <vector>
#include <map>
using namespace std;

// 蛮力法
class Solution {
public:
    int maxPoints(vector<vector<int> > &points) {
        int result = 0;
        for (int i = 0; i < points.size(); ++i) {
            int duplicate = 1; // ??????
            for (int j = i + 1; j < points.size(); ++j) {
                int count = 0;
                long long x1 = points[i][0];
                long long y1 = points[i][1];
                long long x2 = points[j][0];
                long long y2 = points[j][1];
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate;
                    continue;
                }
                
                for (int k = 0; k < points.size(); ++k) {
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    if (x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x2 * y1 - x1 * y3 == 0) {
                        ++count;
                    }
                }
                result = max(result, count);
            }
            result = max(result, duplicate);
        }
        return result;
    }
};
