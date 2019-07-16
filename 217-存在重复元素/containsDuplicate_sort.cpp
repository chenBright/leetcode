#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        // nums.size() 返回的数据类型为 unsighed long，
        // 如果数组长度为 0，再 - 1，结果溢出，最后导致进入循环，数组越界访问
        for (int i = 0; i < static_cast<int>(nums.size()) - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
};