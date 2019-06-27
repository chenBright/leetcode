#include <vector>
using namespace std;

// 格雷码性质：直接排列
class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n; // 即 2 ^ n
        vector<int> result(size, 0);
        for (int i = 1; i < size; ++i) {
            int previous = result[i - 1];
            if (i % 2 == 1) {
                result[i] = previous ^ 1;
            } else {
                int tmp = previous;
                for (int j = 0; j < n; ++j) {
                    if ((tmp & 1) == 1) {
                        previous ^= 1 << (j + 1); // 注意：j从0开始。
                        result[i] = previous;
                        break;
                    }
                    tmp >>= 1;
                }
            }
        }

        return result;
    }
};
