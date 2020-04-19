#include <vector>
#include <cmath>
using namespace std;

// 深度优先搜索
class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }

        int minCount = INT_MAX;
        int sq = sqrt(n);
        helper(n, sq, minCount, 0);

        return minCount;
    }

private:
    void helper(int n, int sq, int& minCount, int count) {
        int c = n / (sq * sq);
        if (n % (sq * sq) == 0) {
            // 如果整除，肯定是当前这种分配方式的最小值。
            minCount = min(minCount, count + c);
        } else {
            // 如果当前数字尽量多取，总个数已经超过 minCount，则即使少取该数字，总个数也会超过 minCount（剪枝）。
            for (int i = c; i >= 0 && count + i < minCount; --i) {
                helper(n - i * sq * sq, sq - 1, minCount, count + i);
            }
        }
    }
};