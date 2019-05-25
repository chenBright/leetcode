class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }

        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) { // 如果是奇数个，则还需要多出来的 x
                res *= x;
            }
            x *= x;
        }

        return n < 0 ? 1 / res : res;
    }
};