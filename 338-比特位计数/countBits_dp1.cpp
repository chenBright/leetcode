#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        int i = 0;
        int b = 1;
        while (b <= num) {
            // 计算区间 [b, 2b)（因为 i < b）或者 [b, num)
            while (i < b && i + b <= num) {
                // 区间 [b, 2b) 的结果可通过 [0, b) 的结果求出
                // dp[i + b] = dp[i] + 1，其中 i < b = 2 ^ m
                result[i + b] = result[i] + 1;
                ++i;
            }
            i = 0;
            b <<= 1;
        }

        return result;
    }
};
