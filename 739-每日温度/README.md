# 739-每日温度

## 题目

leetcode：[739-每日温度](https://leetcode-cn.com/problems/daily-temperatures/)

## 单调栈

使用`单调栈`保存温度递增的索引序列。遍历数组：

- 如果当前值大于`单调栈`的栈顶元素，则将栈顶元素出栈，并计算时间差；
- 否则，将当前元素的索引`push`到栈中。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) {
            return vector<int>();
        }

        int length = T.size();
        vector<int> result(length, 0);
        stack<int> s;

        for (int i = 0; i < T.size(); ++i) {
            while (!s.empty() && T[s.top()] < T[i]) {
                int top = s.top();
                s.pop();
                result[top] = i - top;
            }
            s.push(i);
        }

        return result;
    }
};
```

### 动态规划

参考[LeetCode  Angus-Liu 的评论](https://leetcode-cn.com/problems/daily-temperatures/comments/13032)。

从尾开始遍历数组，而`result[T.size() - 1]`肯定为0。

- 如果`T[i] < T[i + 1]`，则`result[i] = 1`；
- 如果`T[i] > T[i + 1]`，
  - 如果`result[i + 1] = 0`，那么`result[i] = 0`；
  - 如果`result[i + 1] != 0`，那就比较`T[i]`和`T[i + 1 + result[i + 1]]`（即将第i天的温度与比第i+1天大的那天的温度进行比较）。

时间复杂度：***O(n)***。

```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) {
            return vector<int>();
        }

        int length = T.size();
        vector<int> result(length, 0);

        for (int i = length - 2; i >= 0; --i) {
            for (int j = i + 1; j < length; j += result[j]) {
                if (T[i] < T[j]) {
                    result[i] = j - i;
                    break;
                } else if (result[j] == 0) {
                    result[i] = 0;
                    break;
                }
            }
        }

        return result;
    }
};
```