class Solution {
public:
    bool isPowerOfTwo(int n) {
        long tmp = 1;
        while (tmp < n) {
            tmp *= 2;
        }

        return tmp == n;
    }
};