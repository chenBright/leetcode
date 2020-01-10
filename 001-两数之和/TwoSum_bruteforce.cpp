#include <vector>
#include <algorithm>
using namespace std;

// 暴力法
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }

        return result;
    }
};