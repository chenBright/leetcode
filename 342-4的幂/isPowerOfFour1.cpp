#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (static_cast<int>(log10(num) / log10(4)) - log10(num) / log10(4) == 0);
    }
};