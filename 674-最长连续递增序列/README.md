# 674-最长连续递增序列

## 题目

leetcode：[674-最长连续递增序列](https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/)

## 实现

```c++
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int result = 1;
        int tmp = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                ++tmp;
            } else {
                tmp = 1;
            }
            result = max(result, tmp);
        }

        return result;
    }
};
```

