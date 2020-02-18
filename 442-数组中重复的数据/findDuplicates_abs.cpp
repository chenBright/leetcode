#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            int num = abs(nums[i]);
            if (nums[num - 1] > 0) {
                // 标记 num 对应索引
                nums[num - 1] *= -1;
            } else {
                // 已经被标记过，则将其加入结果中
                result.push_back(num);
            }
        }

        return result;
    }
};