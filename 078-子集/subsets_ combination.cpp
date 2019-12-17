#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;

        result.push_back(vector<int>()); // 空集合
        for (int i = 0; i < nums.size(); ++i) {
            int resultLength = result.size();
            // 当前数字与已经存在的子集组合成新的组合，并将其加入到结果中。
            for (int j = 0; j < resultLength; ++j) {
                auto tmp = result[j];
                tmp.push_back(nums[i]);
                result.push_back(tmp);
            }
        }

        return result;
    }
};
