#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int expectedSum = nums.size() * (nums.size() + 1) / 2;
        int actualSum = accumulate(nums.begin(), nums.end(), 0);

        return expectedSum - actualSum;
    }
};
