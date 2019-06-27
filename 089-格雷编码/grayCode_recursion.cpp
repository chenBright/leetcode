#include <vector>
using namespace std;

// 格雷码性质：镜射排列
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1 << n);

        grayCodeRecursion(result, 1, n);

        return result;
    }

private:
    void grayCodeRecursion(vector<int> &result, int bitCount, int n) {
        if (bitCount > n) {
            return;
        }

        for (int i = 1 << (bitCount - 1), j = i - 1; i < 1 << bitCount; ++i, --j) {
            result[i] = result[j] + (1 << (bitCount - 1));
        }

        grayCodeRecursion(result, bitCount + 1, n);
    }
};
