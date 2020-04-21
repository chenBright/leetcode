#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            //  i >> 1 后比原来 i “在最右边少了一位”，
            // 如果原来 i 的最低位是 1，则 result[i] = result[i >> 1] + 1；
            // 如果原来 i 的最低位是 0，则 result[i] = result[i >> 1]。
            // i & 1 或者 i % 2 可用于判断做低位是否为 1。
            // result[i] = result[i / 2] + (i % 2);
            result[i] = result[i >> 1] + (i & 1);
        }

        return result;
    }
};
