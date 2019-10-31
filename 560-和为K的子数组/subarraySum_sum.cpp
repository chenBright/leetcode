#include <vector>
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
        vector<int> sums(length + 1, 0);
        for (int i = 1; i <= length; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int start = 0; start < length; ++start) {
            for (int end = start + 1; end <= length; ++end) {
                // 计算 [start, end) 的累积和
                if (sums[end] - sums[start] == k) {
                    ++result;
                }
            }
        }

        return result;
    }
};
