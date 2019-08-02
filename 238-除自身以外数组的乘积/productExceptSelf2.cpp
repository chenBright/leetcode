#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = nums.size();
        vector<int> result(len);

        int product = 1;
        for (int i = 0; i < len; ++i) {
            result[i] = product;
            product *= nums[i];
        }

        product = 1;
        for (int j = len - 1; j >= 0; --j) {
            result[j] = product;
            product *= nums[j];
        }

        return result;
    }
};
