#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = nums.size();
        vector<int> result(len);

        int product = 1;
        vector<int> left(len, 1); // left[i] 表示 nums[i] 左边乘积
        for (int i = 0; i < len; ++i) {
            left[i] = product;
            product *= nums[i];
        }

        product = 1;
        vector<int> right(len, 1); // right[i] 表示 nums[i] 右边乘积
        for (int j = len - 1; j >= 0; --j) {
            right[j] = product;
            product *= nums[j];
        }

        for (int k = 0; k < len; ++k) {
            result[k] = left[k] * right[k];
        }

        return result;
    }
};
