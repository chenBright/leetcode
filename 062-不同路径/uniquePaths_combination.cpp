#include <vector>
using namespace std;

class Solution {
public:
    // m表示列，n表示行
    int uniquePaths(int m, int n) {
        /**
         * 机器人一定会走 m + n - 2 步，即向下走 m - 1 步，向右走 n - 1 步。
         * 机器人从 m + n - 2 步中挑 m - 1 步向下走或者挑 n - 1 步向右走，
         * 即 C((m + n - 2), (m - 1))或者 C((m + n - 2), (n - 1))。
         * 其实两个数相等，例如 C(12, 9) 等于 C(12, 3)。
         */
        return combinationNum(m + n - 2, m - 1);
        // return combinationNum(m + n - 2, n - 1);
    }

private:
    // 计算组合数
    int combinationNum(int n, int k) {
        long long res = 1;
        if (k > n - k) {
            k = n - k;
        }
        for (int i = n, x = 1; i > n - k; --i, ++x) {
            /** 由于用到了阶乘，极容易导致数据溢出，应用中应采用边乘边除的方法。
             * 除法一般需要用到浮点数，但通过数论中的定理，可以通过整数运算实现。
             */
            res *= i;
            res /= x;
        }

        return static_cast<int>(res);
    }
};