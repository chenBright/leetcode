# 015-三数之和

## 题目

leetcode：[015-三数之和](https://leetcode-cn.com/problems/3sum/)


## 双指针法

1. 先将数组排序。
2. 定义三个指针***i，j，k***，遍历i，那么这个问题就可以转化为在i之后的数组中寻找***nums[j]+nums[k]=-nums[i]***的问题，也就将三数之和问题转变为二数之和。

（另外需要注意的是***去重***的问题）

双指针法的时间复杂度为***O(n^2)***。

```c++
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) { // 去重
                int j = i + 1;
                int k = nums.size() - 1;
                // 双指针
                while (j < k) {
                    int sum = nums[j] + nums[k];
                    if (sum == -nums[i]) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        res.push_back(temp);
                        ++j;
                        --k;
                        while (j < k && nums[j] == nums[j - 1]) { // 去重
                            ++j;
                        }
                        while (j <k && nums[k] == nums[k + 1]) { // 去重
                            --k;
                        }
                    } else if (sum < -nums[i]) {
                        ++j;
                    } else {
                        --k;
                    }
                }
            }
        }

        return res;
    }
};
```

