# 179-最大数

## 题目

leetcode：[179-最大数](https://leetcode-cn.com/problems/largest-number/)

## 自定义排序规则

自定义排序规则：比较ab和ba。

1. 如果ab > ba，则a比b大。
2. 否则，b比a大。

```c++
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int length = nums.size();
        vector<string> strs(length);
        for (int i = 0; i < length; ++i) {
            strs[i] = to_string(nums[i]);
        }

         // 从大到小排序
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

         // 后面的数字一定是 0
        if (strs[0] == "0") {
            return "0";
        }

        string str;
        for (const auto& s : strs) {
            str.append(s);
        }

        return str;
    }
};
```

