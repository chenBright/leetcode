#include <cstdint>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            count += n % 2; // 获取n的最右边的位
            n >>= 1; // 删除最右边的位
        }

        return count;
    }
};