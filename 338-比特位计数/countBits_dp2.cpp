#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        int i = 0;
        int b = 1;
        for (int i = 1; i <= num; ++i) {
            // result[i] = result[i / 2] + (i % 2);
            result[i] = result[i >> 1] + (i & 1);
        }

        return result;
    }
};
