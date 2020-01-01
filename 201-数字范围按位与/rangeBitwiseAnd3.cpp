class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // return n > m ? (rangeBitwiseAnd(m / 2, n / 2) << 1) : m;
        return n > m ? (rangeBitwiseAnd(m >> 1, n >> 1) << 1) : m;
    }
};