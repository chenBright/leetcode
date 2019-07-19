class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 如果 n 是 2 的幂，则 n 的二进制的最高位为 1，其他位为 0。
        // 此时，n - 1 的二进制中对应 n 的最高位的位为 0，后面的位全为 1。
        // 则 n & (n - 1) 一定等于 0
        return n > 0 && !(n & (n - 1));
    }
};