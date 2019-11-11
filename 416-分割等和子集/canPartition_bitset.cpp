#include <vector>
#include <bitset>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 题目中说了数组的长度、每个数字的大小都不会超过 100，那么最大的和为 10000。
        // 10000 一半就是 5000，前面再加上 0，就是 5001 了。
        bitset<5001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 和为奇数，则直接返回 false
        if (sum % 2 != 0) {
            return false;
        }

        for (const auto& n : nums) {
            bits |= bits << n;
        }

        return bits[sum >> 1];
    }
};
