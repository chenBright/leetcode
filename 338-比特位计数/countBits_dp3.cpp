#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        int i = 0;
        int b = 1;
        for (int i = 1; i <= num; ++i) {
            // i & (i - 1) 可以快速移除最右边的 bit 1，
            // 即 i 比 i & (i - 1) 多一位 1。
            result[i] = result[i & (i - 1)] + 1;
        }

        return result;
    }
};
