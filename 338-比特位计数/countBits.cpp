#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        for (int i = 0; i <= num; ++i) {
            result[i] = bits(i);
        }

        return result;
    }

private:
    int bits(int num) {
        int count = 0;
        while (num) {
            num &= num - 1; // 快速移除最右边的 bit 1
            ++count;
        }

        return count;
    }
};
