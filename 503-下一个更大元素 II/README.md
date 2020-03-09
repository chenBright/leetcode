# 503-下一个更大元素 II

## 题目

leetcode：[503-下一个更大元素 II](https://leetcode-cn.com/problems/next-greater-element-ii/)

## 单调栈

在[496-下一个更大元素 I](./496-下一个更大元素%20I/README.md)的基础上，该题需要遍历两次。

```c++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length, -1); // 默认为 -1
        if (nums.empty()) {
            return result;
        }

        stack<pair<int, int> > s; // <元素, 索引>
        for (int i = 0; i < length; ++i) {
            while (!s.empty() && nums[i] > s.top().first) {
                result[s.top().second] = nums[i];
                s.pop();
            }
            s.push(make_pair(nums[i], i));
        }

        for (int j = 0; j < length; ++j) {
            while (!s.empty() && nums[j] > s.top().first) {
                result[s.top().second] = nums[j];
                s.pop();
            }
            // 如果栈为空，则都找到下一个最大元素
            // 如果当前遍历的的元素索引等于栈顶元素的索引，
            // 则表示已经遍历到栈顶元素本身了，不存在下一个最大元素。
            if (s.empty() || j == s.top().second) {
                break;
            }
        }

        return result;
    }
};
```

