#include <cmath>

// 蛮力法
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i < n; ++i) {
            bool flag = true;
            for (int j = 2; j <= sqrt(i); ++j) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ++count;
            }
        }

        return count;
    }
};