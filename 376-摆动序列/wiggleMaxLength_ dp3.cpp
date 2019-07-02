#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }

        int up = 1; // 上升序列的长度
        int down = 1; //下降序列的长度
        for (int i = 1; i< len; ++i) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }

        return max(up, down);
    }
};