#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        long sum1 = 3 * accumulate(s.begin(), s.end(), static_cast<long>(0));
        long sum2 = accumulate(nums.begin(), nums.end(), static_cast<long>(0));
        return (sum1 - sum2) / 2;
    }
};