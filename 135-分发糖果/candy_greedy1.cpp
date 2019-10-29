#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int length = ratings.size();
        vector<int> left2right(length, 1);
        vector<int> right2left(length, 1);
        // 更新与左边孩子的关系
        for (int i = 1; i < length; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left2right[i] = left2right[i - 1] + 1;
            }
        }

        // 更新与右边孩子的关系
        for (int j = length - 2; j >= 0; --j) {
            if (ratings[j] > ratings[j + 1]) {
                right2left[j] = right2left[j + 1] + 1;
            }
        }

        int result = 0;
        for (int k = 0; k < length; ++k) {
            // 取最大值才满足条件
            result += max(left2right[k], right2left[k]);
        }

        return result;
    }
};
