# 300-最长上升子序列

## 题目

leetcode：[300-最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

## 蛮力法

找出数组的所有上升子序列，并从中找出最长的子序列。

参考[LeetCode官方题解](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode)。

时间复杂度：***O(2^n)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        return lengthOfLIS(nums, INT_MIN, 0);
    }
private:
    int lengthOfLIS(vector<int> &nums, int previous, int currentPositon) {
        if (currentPositon >= nums.size()) {
            return 0;
        }

        int length1 = 0;
        if (nums[currentPositon] > previous) {
            length1 = 1 + lengthOfLIS(nums, nums[currentPositon], currentPositon + 1);
        }

        int length2 = lengthOfLIS(nums, previous, currentPositon + 1);

        return max(length1, length2);
    }
};
```

## 缓存中间结算结果的蛮力法

蛮力法中存在很多重复的计算，可以使用一个二维数组将`[start, end]`的最长子序列缓存起来。

参考[LeetCode官方题解](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode)。

时间复杂度：***O(n^2)***。递归树的大小可以达到***n^2***。

空间复杂度：***O(n^2)***。

```c++
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<vector<int> > memory(nums.size(), vector<int>(nums.size(), -1));
        return lengthOfLIS(nums, -1, 0, memory);
    }
private:
    int lengthOfLIS(vector<int> &nums, int previousPosition, int currentPositon, vector<vector<int> > &memory) {
        if (currentPositon >= nums.size()) {
            return 0;
        }

        if (memory[previousPosition + 1][currentPositon] >= 0) {
            return memory[previousPosition + 1][currentPositon];
        }

        int length1 = 0;
        if (previousPosition < 0 || nums[previousPosition] < nums[currentPositon]) {
            length1 = 1 + lengthOfLIS(nums, currentPositon, currentPositon + 1, memory);
        }

        int length2 = lengthOfLIS(nums, previousPosition, currentPositon + 1, memory);

        memory[previousPosition + 1][currentPositon] = max(length1, length2);

        return memory[previousPosition + 1][currentPositon];
    }
};
```

## 动态规划

### 从尾到头

使用数组`dp`记录当前位置起的最长子序列的长度，`dp[i]`表示以`nums[i]`为序列的第一个数字的最长子序列的长度。

从尾开始遍历`nums`数组，`nums[i]`与以`nums[j]（j = i + 1 ... nums.size() - 1）`为起点的子序列能否组成上升序列：

- 如果能，则`dp[i] = 1 + dp[j]`；
- 否则，`dp[i] = 1`。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int len = nums.size();
        // dp[i] 表示以 nums[i] 为序列的第一个数字的最长子序列的长度
        vector<int> dp(len, 1);
        int maxLength = 1;
        for (int i = len - 1; i >= 0; --i) {
            int tmpLength = 1;
            // nums[i] 与以 nums[j]（j = i + 1 ... nums.size() - 1）为起点的子序列能否组成上升序列
            for (int j = i + 1; j < len; ++j) {
                if (nums[i] < nums[j]) {
                    // 如果能，则 dp[i] = 1 + dp[j]
                    tmpLength = max(tmpLength, 1 + dp[j]);
                }
            }
            dp[i] = max(dp[i], tmpLength);
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
```

### 从头到尾

[LeetCode官方题解](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode)的动态规划的实现是从头开始遍历的，`dp[i]`表示以`nums[i]`结尾的最长子序列的长度。

从头开始遍历`nums`数组，`nums[i]`与以`nums[j]（j = 0 ... i - 1）`为末尾的子序列能否组成上升序列：

- 如果能，则`dp[i] = 1 + dp[j]`；
- 否则，`dp[i] = 1`。

时间复杂度：***O(n^2)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int len = nums.size();
        vector<int> dp(len, 1);
        int maxLength = 1;
        for (int i = 1; i < len; ++i) {
            int tmpLength = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    tmpLength = max(tmpLength, 1 + dp[j]);
                }
            }
            dp[i] = tmpLength;
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
```
## 动态规划 + 二分查找

参考[博客 解法二、三、四](https://github.com/grandyang/leetcode/issues/300)和[LeetCode官方题解](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode)。

关于使用二分查找替换子序列中的数字的理解：当出现这种情况的时候，该子序列的长度已经确定，不会再变成。而此时出现的数字形成的子序列可能会更长，所以将其放到子序列中合适的位置，以形成新的子序列。

时间复杂度：***O(nlogn)***。

空间复杂度：***O(n)***。

### 实现1

```c++
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int len = nums.size();
        vector<int> dp{nums[0]};
        for (int i = 0; i < len; ++i) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]); // 符合上升序列的要求
            } else {
                // 查找第一个不小于 nums[i] 的值，并用 nums[i] 替换它
                int low = 0;
                int high = dp.size();
                while (low < high) {
                    int mid = (low + high) / 2;
                    if (dp[mid] < nums[i]) {
                        low = mid + 1;
                    } else {
                        high = mid;
                    }
                }
                dp[high] = nums[i];
            }
        }
        
        // 最后，dp 的长度等于上升序列的长度
        return dp.size();
    }
};
```

### 实现2

```c++
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int len = nums.size();
        vector<int> dp;
        for (int i = 0; i < len; ++i) {
            // 查找第一个不小于 nums[i] 的值
            int low = 0;
            int high = dp.size();
            while (low < high) {
                int mid = (low + high) / 2;
                if (dp[mid] < nums[i]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }

            // 如果查找失败，则将 nums[i] 添加到 dp 数组末尾；
            // 如果查找成功，则用 nums[i] 替换它。
            if (high >= dp.size()) {
                dp.push_back(nums[i]);
            } else {
                dp[high] = nums[i];;
            }
        }
        
        // 最后，dp 的长度等于上升序列的长度
        return dp.size();
    }
};
```

### 实现3

```c++
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int len = nums.size();
        vector<int> dp;
        for (int i = 0; i < len; ++i) {
            // 查找第一个不小于 nums[i] 的值
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if (it == dp.end()) {
                dp.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        
        // 最后，dp 的长度等于上升序列的长度
        return dp.size();
    }
};
```
