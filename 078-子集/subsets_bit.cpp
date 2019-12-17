#include <vector>
#include <cmath>
using namespace std;

// 位运算
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        int length = nums.size();

        result.push_back(vector<int>()); // 空集合

        // 每个数字代表一个位，有两种情况（取或不取），总共 2 ^ length 中情况
        int subLength = pow(2, length);
        // 当前取数情况，如果 nums = [1, 2, 3]，则当前 hash = 001(2)
        int hash = 1;
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
            result.push_back(tmp);
            ++hash;
        }

        return result;
    }
};
