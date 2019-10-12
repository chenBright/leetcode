#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        if (nums.empty()) {
            return result;
        }

        sort(nums.begin(), nums.end());
        int previous = 0;
        for (const auto &num : nums) {
            if (num == previous) {
                continue;
            }

            // 将 [previous + 1, num) 中间缺少的数字加入到结果中
            for (int i = previous + 1; i < num; ++i) {
                result.push_back(i);
            }
            previous = num;
        }

        // 将 [previous + 1, num.size()] 中间缺少的数字加入到结果中
        for (int i = previous + 1; i <= nums.size(); ++i) {
            result.push_back(i);
        }

        return result;
    }
};
