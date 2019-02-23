#include <climits>

class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while (x != 0) {
            int n = x % 10;
            x /= 10;

            // 判断溢出
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && n == 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && n == -8)) {
                return 0;
            }

            res = res * 10 + n;
        }

        return res;
    }
};