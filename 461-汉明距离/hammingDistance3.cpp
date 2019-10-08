#include <cstdint>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int bits = x ^ y;
        return hammingWeight(bits);
    }

private:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int i = 32;
        while (n) {
            n &= n - 1; // 快速移除最右边的 bit 1
            ++count;
        }

        return count;
    }
};