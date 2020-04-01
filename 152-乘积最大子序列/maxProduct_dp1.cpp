#include <vector>
using namespace std;

/**
 * 1. 如果负数个数为偶数，则整个数组的各个值相乘为最大值；
 * 2. 如果负数个数为奇数，则从左边开始，乘到最后一个负数停止，有一个“最大值”，从右边也有一个“最大值”，比较，得出最大值。
 * 3. 出现0，可以看成将数组拆分两部分，分别求子数组的最大值。
 */
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return nums[0];
        }

        int maxProduction = INT_MIN; // 最大乘积

        int product = 1;
        // 从左到右计算
        for (int i = 0; i < len; ++i) {
            product *= nums[i];
            // 如果负数个数为奇数，max 在遍历到最后一个负数及以后的数字，就不再更新
            maxProduction = max(maxProduction, product);
            // 遇到 0，停止连乘，初始化乘积为 1
            if (nums[i] == 0) {
                product = 1;
            }
        }

        product = 1;
        // 从右向左计算
        for (int j = len - 1; j >= 0; --j) {
            product *= nums[j];
            // 同上
            maxProduction = max(maxProduction, product);
            if (nums[j] == 0) {
                product = 1;
            }
        }

        return maxProduction;
    }
};