class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) {
            return -1;
        } else if (x == 0) {
            return 0;
        }

        long i = 0;
        while (i * i <= x) {
            ++i;
        }

        return --i;
    }
};