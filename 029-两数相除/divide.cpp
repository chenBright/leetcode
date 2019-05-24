#include <climits>
#include <cstdlib>

#define LIMIT 0x80000000

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool negative = (dividend ^ divisor) < 0; // 用异或来计算是否符号相异
        unsigned int t = dividend == INT_MIN ? LIMIT : abs(dividend);
        unsigned int d = divisor == INT_MIN ? LIMIT : abs(divisor);
        unsigned int result = 0;
        for (int i = 31; i >= 0; i--) {
            if ((t >> i) >= d) { // 找出足够大的数 2^n*divisor
                result += ((unsigned int)1) << i; // 将结果加上2^n
                t -= d << i; // 将被除数减去2^n*divisor
            }
        }

        if (result == LIMIT) { // 特殊数不能将unsigned int转为int
            return INT_MIN;
        }
        else {
            return negative ? -(int)result : (int)result; // 符号相异取反
        }
    }
};