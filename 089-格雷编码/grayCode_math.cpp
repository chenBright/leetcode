#include <vector>
using namespace std;

// 格雷码性质：二进制数转格雷码
class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n; // 即 2 ^ n
        vector<int> result(size, 0);
        for (int i = 0; i < size; ++i) {
            // G(n)=B(n+1) XOR B(n)
            result[i] = i ^ (i >> 1);
        }

        return result;
    }
};
