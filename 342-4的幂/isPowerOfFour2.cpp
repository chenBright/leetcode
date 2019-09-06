#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        // 0x55555555（八进制） == 1010101010101010101010101010101（二进制）
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
};