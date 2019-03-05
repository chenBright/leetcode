#include <vector>
using namespace std;

// 分治
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        return maxSum(nums, 0 ,nums.size() - 1);
    }

private:
    int maxSum(vector<int> &nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int center = (left + right) / 2;
        int maxLeftSum = maxSum(nums, left, center); // 计算左半部分最大子段和
        int maxRightSum = maxSum(nums, center + 1, right); // 计算右半部分最大子段和

        /**
         * 计算包含中间，同时涉及到左右两部分的最大子段和
         */
        int maxLeftBorderSum = nums[center], leftBorderSum = 0;
        for (int i = center; i >= left; --i) {
            leftBorderSum += nums[i];
            if (leftBorderSum > maxLeftBorderSum) {
                maxLeftBorderSum = leftBorderSum;
            }
        }

        int maxRightBorderSum = nums[center + 1], rightBorderSum = 0;
        for (int j = center + 1; j <= right; ++j) {
            rightBorderSum += nums[j];
            if (rightBorderSum > maxRightBorderSum) {
                maxRightBorderSum = rightBorderSum;
            }
        }

        return max(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    }

    int max(int n, int m, int l) {
        int max;
        max = n > m ? n : m;
        if (l > max) {
            max = l;
        }

        return max;
    }
};