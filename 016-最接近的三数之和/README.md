# 016-最接近的三数之和

## 题目

leetcode：[016-最接近的三数之和](https://leetcode-cn.com/problems/3sum-closest/)


## 双指针法

参考[015-三数之和](../015-三数之和)的解法。

```c++
class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int length = nums.size();
        if (length < 3) {
            return -1;
        }

        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];
        // 不需要完全遍历数组，主需要遍历到 nums[length - 3]即可。
        // 因为结果为三元组，nums[length - 2]、nums[length - 1]
        // 没有足够的元素与之组成三元组，所以不需要遍历它们。
        for (int i = 0; i <= length - 3; ++i) {
            int j = i + 1;
            int k = length - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(closestSum - target) > abs(sum - target)) {
                    closestSum = sum;
                }

                if (sum == target) {
                    return closestSum;
                } else if (sum < target) {
                    ++j;
                } else {
                    --k;
                }
            }
        }

        return closestSum;
    }
};
```
