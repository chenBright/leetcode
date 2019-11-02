#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        for (int i = 0; i <= num; ++i) {
            result[i] = bitset<32>(i).count();
        }

        return result;
    }
};
