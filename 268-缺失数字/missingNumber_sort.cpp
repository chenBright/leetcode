#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        if (nums[nums.size() - 1] != nums.size()) { // 判断 n 是否出现在末位
            return nums.size();
        } else if (nums[0] != 0) { // 判断 0 是否出现在首位
            return 0;
        }

        for (int i = 0; i + 1 < nums.size(); ++i) {
            int expectedNum = nums[i] + 1;
            if (expectedNum != nums[i + 1]) {
                return expectedNum;
            }
        }

        return -1; // 未缺失任何数字（保证函数有返回值）
    }
};
