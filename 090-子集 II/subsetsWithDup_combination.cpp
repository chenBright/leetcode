#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        vector<vector<int> > res;
        int length = nums.size();
        if (length == 0) {
            return res;
        }

        sort(nums.begin(), nums.end());

        int left = 0; // 生成子集的起点
        int right = 1; // 生成子集的终点
        int subsetsLen = 0; // 生成子集的数量
        res.push_back(vector<int>()); // 空集合
        for (int i = 0; i < length; ++i) {
            int resLength = res.size();
            if (i != 0 && nums[i] == nums[i - 1]) { // 如果数字与前一个数字相等，则至于上次生成的子集组合
                left = resLength - subsetsLen;
            } else {
                left = 0;
            }
            right = resLength;
            subsetsLen = right - left; // 这次生成的子集的数量
            vector<int> temp;
            // 组合
            for (int j = left; j < right; ++j) {
                temp.clear();
                temp.assign(res[j].begin(), res[j].end());
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }

        return res;
    }
};