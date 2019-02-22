#include <vector>
#include <algorithm>
using namespace std;

// 暴力破解
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        if (nums.empty()) {
            return res;
        }

        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }

        return res;
    }
};