#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (const auto& n : nums) {
            result ^= n;
        }

        return result;
    }
};