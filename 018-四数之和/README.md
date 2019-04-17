# 018-四数之和

## 题目

leetcode：[018-四数之和](https://leetcode-cn.com/problems/4sum/)


## 双指针法

参考[001-两数之和](https://leetcode-cn.com/problems/two-sum/)和[018-四数之和](https://leetcode-cn.com/problems/4sum/)，将“四数之和”转化为“三数之和”，再转化为“两数之和”。（注意去重）

```c++
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int> > res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) { // 去重
                continue;
            }
            for (int j = i + 1; j < len; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) { // 去重
                    continue;
                }
                int m = j + 1;
                int n =len - 1;
                while (m < n) {
                    int sum = nums[i] + nums[j] + nums[m] + nums[n];
                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[m], nums[n]};
                        res.push_back(temp);
                        ++m;
                        --n;
                        while (m < n && nums[m] == nums[m - 1]) { // 去重
                            ++m;
                        }
                        while (m < n && nums[n] == nums[n + 1]) { // 去重
                            --n;
                        }
                    } else if (sum < target) {
                        ++m;
                    } else {
                        --n;
                    }
                }
            }
        }
        return res;
    }
};
```

