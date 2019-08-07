#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int expectedSum = nums.size() * (nums.size() + 1) / 2;
        int actualSum = 0;
        for (const auto &num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};
