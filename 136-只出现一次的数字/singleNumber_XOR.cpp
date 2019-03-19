#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }

        int result = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            result ^= *it;
        }

        return result;
    }
};