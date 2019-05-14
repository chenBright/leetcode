#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > res;
        int length = nums.size();
        if (length == 0) {
            return res;
        }

        res.push_back(vector<int>()); // 空集合
        for (int i = 0; i < length; ++i) {
            vector<int> temp;
            int resLength = res.size();
            // 当前数字与已经存在的子集组合
            for (int j = 0; j < resLength; ++j) {
                temp.clear();
                temp.assign(res[j].begin(), res[j].end());
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }

        return res;
    }
};