#include <vector>
#include <unordered_set>
#include <numeric>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return 2 * accumulate(s.begin(), s.end(), static_cast<long>(0)) - accumulate(nums.begin(), nums.end(), static_cast<long>(0));
    }
};