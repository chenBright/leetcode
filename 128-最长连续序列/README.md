# 128-最长连续序列

## 题目

leetcode：[128-最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence/)

## HashSet

### 实现1

参考[LeetCode官方题解](https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/zui-chang-lian-xu-xu-lie-by-leetcode/)。

```c++
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int result = 0;
        for (const auto &num : nums) {
            // 找到连续序列的第一个数字
            if (s.count(num - 1) == 0) {
                int currentNum = num;
                int tmpResult = 1;
                // 统计连续序列的长度
                while (s.count(currentNum + 1) != 0) {
                    ++currentNum;
                    ++tmpResult;
                }

                result = max(result, tmpResult);
            }
        }

        return result;
    }
};
```

### 实现2

参考[LeetCode评论区“胡明”的思路](https://leetcode-cn.com/problems/longest-consecutive-sequence/comments/91744)。

```c++
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        unordered_set<int> s(nums.begin(), nums.end());

        int result = 0;
        for (const auto &num : nums) {
            if (s.count(num) != 0) {
                s.erase(num);
                int left = num - 1;
                int right = num + 1;

                // (left, right)
                // 找到序列的第一个数字前一个数字
                while (s.count(left) != 0) {
                    s.erase(left--);
                }

                // 找到序列的第一个数字后一个数字
                while (s.count(right) != 0) {
                    s.erase(right++);
                }

                result = max(result, right - left - 1);
            }
        }

        return result;
    }
};
```

## HashMap

参考[LeetCode评论区“江五渣”的思路](https://leetcode-cn.com/problems/longest-consecutive-sequence/comments/13385)。

```c++
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> m; // <数字，所在连续序列的长度>
        int result = 0;
        for (const auto &num : nums) {
            if (m.count(num) == 0) {
                // num - 1 所在连续序列的长度
                int left = m.count(num - 1) ? m[num - 1] : 0;
                // num + 1 所在连续序列的长度
                int right = m.count(num + 1) ? m[num + 1] : 0;
                int tmpResult = left + 1 + right;
                // 更新所在连续序列的长度
                m[num] = tmpResult;
                m[num - left] = tmpResult;
                m[num + right] = tmpResult;

                result = max(result, tmpResult);
            }
        }

        return result;
    }
};
```

