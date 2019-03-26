#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int i=32;
        while(i--)
        {
            ans <<= 1; // 翻转已处理的位
            ans += n & 1; // 将n中最右边的位取出，加到ans中
            n >>= 1; // 删除最右边的位
        }
        return ans;
    }
};