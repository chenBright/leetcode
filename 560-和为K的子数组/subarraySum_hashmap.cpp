#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        if (nums.empty()) {
            return result;
        }

        int length = nums.size();
        // sums[i] 表示 [1 .. i]（第 i 个元素）的和。
        unordered_map<int, int> m;
        m[0] = 1;
        int sum = 0;
        for (int i = 0; i < length; ++i) {
            sum += nums[i];
            if (m.count(sum - k) != 0) {
                result += m[sum - k];
            }
            ++m[sum];
        }

        return result;
    }
};
