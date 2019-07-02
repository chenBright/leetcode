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
        for (int i = 1; i< len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    upDp[i] = max(upDp[i], downDp[j] + 1);
                } else if (nums[i] < nums[j]) {
                    downDp[i] = max(downDp[i], upDp[j] + 1);
                }
            }
        }

        return 1 + max(upDp[len - 1], downDp[len - 1]); // 加上第一个
    }
};