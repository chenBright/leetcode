class Solution {
public:
    bool isPowerOfTwo(int n) {
        long tmp = 1;
        while (tmp <= n) {
            if (tmp == n) {
                return tmp;
            }

            tmp *= 2;
        }

        return false;
    }
};