#include <vector>
#include <cmath>
using namespace std;

// 位运算
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        int length = nums.size();
        // 每个数字代表一个位，有两种情况（取或不取），总共 2 ^ length 种组合。
        int subLength = pow(2, length);

        vector<vector<int> > result;
        result.reserve(subLength + 1); // 2 ^ length 种组合 + 空集合


        // 当前取数情况，如果 nums = [1, 2, 3]，则当前 hash = 000(2)，表示空集合。
        int hash = 0;
        while (hash < subLength) {
            vector<int> tmp;
            for (int i = 0; i < length; ++i) {
                // 表示是否取第 i 位，1 表示取，0 表示不取。
                // 每次向左移1位。
                int a = 1 << i;
                if (a & hash) {
                    tmp.push_back(nums[i]);
                }
            }
            result.emplace_back(std::move(tmp));
            ++hash;
        }

        return result;
    }
};
