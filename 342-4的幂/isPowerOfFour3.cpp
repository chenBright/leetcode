#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        // 4的次方数，减1之后可以被3整除
        // return num > 0 && !(num & (num - 1)) && num % 3 == 1;
        return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
    }
};