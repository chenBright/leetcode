#include <cmath>

class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) {
            return -1;
        } else if (x == 0) {
            return 0;
        }

        double xk = 1;
        double xk1 = 0;
        double err = 1e-6; // 误差，1e-6就是1乘10的-6次幂
        while (abs(xk - xk1) > err) { // 循环退出的条件是真正解与近似解的误差进入允许的范围
            xk1 = xk;
            xk = (xk + x / xk) / 2; // 迭代公式
        }

        return xk;
    }
};