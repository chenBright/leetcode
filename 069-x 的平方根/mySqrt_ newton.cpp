#include <cmath>

class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) {
            return -1;
        } else if (x == 0) {
            return 0;
        }

        double result = 1;
        double lastResult = 0;
        double eps = 1e-6; // 误差：1e-6
        // 循环退出的条件是真正解与近似解的误差进入允许的范围
        while (abs(result - lastResult) > eps) {
            lastResult = result;
            result = (result + x / result) / 2; // 迭代公式
        }

        return result;
    }
};