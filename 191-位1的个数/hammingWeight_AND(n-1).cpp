#include <cstdint>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= n - 1; // 快速移除最右边的 bit 1
            ++count;
        }

        return count;
    }
};