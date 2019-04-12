#include <vector>
#include <cmath>
using namespace std;

// 深度优先搜索
class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return -1;
        }

        minCount = INT_MAX;

        int nums = static_cast<int>(sqrt(n));

        numSquaresRecursion(n, nums, 0); 

        return minCount;       
    }

private:
    int minCount;
    void numSquaresRecursion(int n, int sq, int count) {
        int a = n / (sq * sq);
        if (n % (sq * sq) == 0) { // 当整除，肯定是当前这种分配方式的最小值
            minCount = min(minCount, count + a);
        } else {
            // 如果当前数字尽量多取，总个数已经超过 minCount，则少取该数字，总个数也会超过 minCount（剪枝？）
            for (int i = a; i >= 0 && count + i < minCount; --i) {
                numSquaresRecursion(n - i * sq * sq, sq - 1, count + i);
            }
        }
    }
};