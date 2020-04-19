#include <vector>
#include <queue>
#include <cmath>
using namespace std;

/**
 * 四平方定理：任何一个正整数都可以表示成不超过四个整数的平方之和。
 * 推论：满足四数平方和定理的数 n（四个整数的情况），必定满足 n = 4^a(8b+7)。
 */
class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 0;
        }

        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }

        int a = 0;
        while (a * a <= n) {
            int b = static_cast<int>(sqrt(n - a * a));
            if (a * a + b * b == n) {
                if (a != 0 && b != 0) {
                    return 2;
                } else {
                    return 1;
                }
            }
            ++a;
        }

        return 3;
    }
};
