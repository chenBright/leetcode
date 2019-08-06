#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int missing = nums.size(); // n
        for (int i = 0; i < nums.size(); ++i) {
            // i 的值：[0, n - 1]
            // nums[i] 的值：[0 ... missing - 1]、[missing + 1, n]
            missing ^= i ^ nums[i];
        }

        return missing;
    }
};
