# 496-下一个更大元素 I

## 题目

leetcode：[496-下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i/)

## 单调栈

参考[LeetCode官方题解](https://leetcode-cn.com/problems/next-greater-element-i/solution/xia-yi-ge-geng-da-yuan-su-i-by-leetcode/)。

1. 遍历数组`nums2`，当当前元素小于栈顶元素时，继续将它入栈；当当前元素大于栈顶元素时，栈顶元素出栈，此时插入到哈希表中：`m[出栈的元素] = 当前元素`；
2. 当遍历完`nums2`后，将栈中的元素出栈，插入到哈希表，其值为`-1`；
3. 遍历数组`nums1`，从哈希表中找到元素对应的下一个更大的元素，将其添加到结果数组中。

```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.empty() | nums2.empty()) {
            return result;
        }

        stack<int> s; // 单调栈
        unordered_map<int, int> m;
        for (const auto& num : nums2) {
            while (!s.empty() && num > s.top()) {
                m[s.top()] = num; // 栈顶元素下一个的元素为 num
                s.pop();
            } // 保持栈内元素从栈底到栈顶单调不增
            s.push(num);
        }

        // 栈中剩下的元素不存在下一个更大的元素
        while (!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }

        for (const auto& num : nums1) {
            result.push_back(m[num]);
        }

        return result;
    }
};
```

