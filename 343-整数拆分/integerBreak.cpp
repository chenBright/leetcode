#include <cmath>

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 1) {
            return -1;
        } else if (n <= 3) {
            return n - 1;
        }

        int a = n / 3;
        int b = n % 3;
        if (b == 0) {
            return pow(3, a);
        } else if (b == 1) {
            return pow(3, a - 1) * 2 * 2;
        } else {
            return pow(3, a) * 2;
        }
    }
};