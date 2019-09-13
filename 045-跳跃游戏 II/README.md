# 045-跳跃游戏 II

## 题目

leetcode：[045-跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)


## 贪心算法

### 实现1

参考[055-跳跃游戏 “贪心算法1”解法](../055-跳跃游戏/README.md#贪心算法1)。

时间复杂度：***O(n)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int jump(vector<int> &nums) {
        int length = nums.size();
        int count = 0;
        int i = 0;
        while (i < length - 1) {
            // 在当前位置分别跳出 1 ~ nums[i] 个长度到达 next 位置，
            // 再看在一步最大能达到的位置，找出最大值，此最大值所对应的 next 值即为应该跳到的位置。
            // 还有一种特殊情况，就是如果该次跳跃可以直接跳到最后一个位置，则 next 为 length - 1，即使它不是最大值。
            int maxNext = INT_MIN;
            int next;
            for (int j = 1; j <= nums[i]; ++j) {
                int nextIndex = min(length - 1, i + j);
                if (nextIndex + nums[nextIndex] > maxNext || nextIndex == length - 1) {
                    next = nextIndex;
                    maxNext = nextIndex + nums[nextIndex];
                }
            }
            ++count;
            i = next;
        }

        return count;
    }
};
```

### 实现2

参考[博客 解法二](https://github.com/grandyang/leetcode/issues/45)。

时间复杂度：***O(n)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int jump(vector<int> &nums) {
        int length = nums.size();
        int count = 0;
        int i = 0; // 当前所在的位置
        int currentNext = 0; // 当前能跳到的最远的位置
        while (currentNext < length) {
            int previousNext = currentNext;
            for (; i < previousNext; ++i) {
                currentNext = max(currentNext, i + nums[i]);
            }
            ++count;

            // 跳不到最后一个位置
            if (previousNext == currentNext) {
                return -1;
            }
        }

        return count;
    }
};
```

### 实现3

参考[博客 解法三](https://github.com/grandyang/leetcode/issues/45)和[实验室小纸贴校外版的博客](http://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html)。

时间复杂度：***O(n)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int jump(vector<int> &nums) {
        int length = nums.size();
        int count = 0;
        int lastNext = 0;
        int currentNext = 0;
        for (int i = 0; i < length - 1; ++i) {
            currentNext = max(currentNext, i + nums[i]);
            if (i == lastNext) {
                lastNext = currentNext;
                ++count;
                if (currentNext >= length - 1) {
                    break;
                }
            }
        }

        return count;
    }
};
```

