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
        while (i--) {
            count += n % 2; // 获取n的最右边的位
            n >>= 1; // 删除最右边的位
        }

        return count;
    }
};