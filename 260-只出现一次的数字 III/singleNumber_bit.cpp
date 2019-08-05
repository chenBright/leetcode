#include <vector>
#include <unordered_map>
#include <numeric>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>()); // 逐一异或
        vector<int> result(2, 0);
        diff &= -diff; // 取最低非0位
        for (const auto &num : nums) {
            // 分组
            if (num & diff) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }

        return result;
    }
};