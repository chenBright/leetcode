# 055-跳跃游戏

## 题目

leetcode：[055-跳跃游戏](https://leetcode-cn.com/problems/jump-game/)

## 贪心算法1

 在当前位置分别跳出`1 ~ nums[i]`个长度到达`next`，再看在一步最大能达到的位置，找出最大值，此最大值所对应的`next`值即为应该跳到的位置。

```c++
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return false;
        }

        int i = 0;
        while (i < length - 1) {
            if (nums[i] == 0) {
                return false;
            }
            // 在当前位置分别跳出 1 ~ nums[i] 个长度到达 next 位置，
            // 再看在一步最大能达到的位置，找出最大值，此最大值所对应的 next 值即为应该跳到的位置
            int maxNext = INT_MIN;
            int next;
            for (int j = 1; j <= nums[i]; ++j) {
                int nextIndex = min(length - 1, i + j);
                int next = nextIndex + nums[nextIndex];
                if (next > maxNext) {
                    maxNext = next;
                    next = i + j;
                }
            }
            i = next;
        }

        return true;
    }
};
```

## 贪心算法2

`dist`表示能跳到最大的位置。

除了判断数组是否遍历完，即`i < length`，还要`dist >= i`表示至少跳出本个位置，即`num[i] != 0`。

```c++
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int length = nums.size();
        int dist = 0;
        // dist 表示能跳到最大的位置
        // dist >= i，表示至少跳出本个位置，即 num[i] != 0
        for (int i = 0; i < length && dist >= i; ++i) {
            dist = max(dist, i + nums[i]);
        }

        return dist >= length - 1;
    }
};
```

