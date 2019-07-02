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

        vector<int> upDp(len); // upDp[i] 表示目前为止最长的以第 i 个元素结尾的上升摆动序列的长度
        vector<int> downDp(len); // downDp[i] 表示目前为止最长的以第 i 个元素结尾的下降摆动序列的长度
        upDp[0] = downDp[0] = 1;
        for (int i = 1; i< len; ++i) {
            if (nums[i] > nums[i - 1]) {
                upDp[i] = downDp[i - 1] + 1;
                downDp[i] = downDp[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                upDp[i] = upDp[i - 1];
                downDp[i] = downDp[i - 1] + 1;
            } else {
                upDp[i] = upDp[i - 1];
                downDp[i] = downDp[i - 1];
            }
        }

        return max(upDp[len - 1], downDp[len - 1]);
    }
};