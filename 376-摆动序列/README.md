# 376-摆动序列

## 题目

leetcode：[376-摆动序列](https://leetcode-cn.com/problems/wiggle-subsequence/)

## 动态规划

参考[LeetCode官方题解](https://leetcode-cn.com/problems/wiggle-subsequence/solution/bai-dong-xu-lie-by-leetcode)。

### 普通动态规划

```c++
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }

        vector<int> upDp(len); // upDp[i] 表示目前为止最长的以第 i 个元素结尾的上升摆动序列的长度
        vector<int> downDp(len); // downDp[i] 表示目前为止最长的以第 i 个元素结尾的下降摆动序列的长度
        for (int i = 1; i< len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    upDp[i] = max(upDp[i], downDp[j] + 1);
                } else if (nums[i] < nums[j]) {
                    downDp[i] = max(downDp[i], upDp[j] + 1);
                }
            }
        }

        return 1 + max(upDp[len - 1], downDp[len - 1]); // 加上第一个
    }
};
```

### 线性动态规划

```c++
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }

        vector<int> upDp(len); // upDp[i] 表示目前为止最长的以第 i 个元素结尾的上升摆动序列的长度
        vector<int> downDp(len); // downDp[i] 表示目前为止最长的以第 i 个元素结尾的下降摆动序列的长度
        upDp[0] = downDp[0] = 1;
        for (int i = 1; i< len; ++i) {
            if (nums[i] > nums[i - 1]) {
                upDp[i] = downDp[i - 1] + 1;
                downDp[i] = downDp[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                upDp[i] = upDp[i - 1];
                downDp[i] = downDp[i - 1] + 1;
            } else {
                upDp[i] = upDp[i - 1];
                downDp[i] = downDp[i - 1];
            }
        }

        return max(upDp[len - 1], downDp[len - 1]);
    }
};
```

### 空间优化的动态规划

```c++
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }

        int up = 1; // 上升序列的长度
        int down = 1; //下降序列的长度
        for (int i = 1; i< len; ++i) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }

        return max(up, down);
    }
};
```

## 贪心算法

### 实现1

该实现是我自己写的，与官方实现思路一样。

```c++
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        
        int result = 1;

        int i = 1;
        // 找第一个与 nums[0] 不相等的元素
        while (i < len && nums[i] == nums[i - 1]) {
            ++i;
        }

        enum Difference {positive, negative}; // nums[i]- nums[i - 1] 为正还是负 
        Difference diff;
        if (i < len) {
            result = 2;
            diff = nums[i] > nums[0] ? positive : negative;
        } else { // 数组元素全都相等
            return result;
        }

        for (int j = i + 1; j < len; ++j) {
            if (diff == positive) {
                if (nums[j] < nums[j - 1]) {
                    ++result;
                    diff = negative;
                }
            } else {
                if (nums[j] > nums[j - 1]) {
                    ++result;
                    diff = positive;
                }
            }
        }

        return result;
    }
};
```

### 实现2（官方实现）

```c++
class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        
        int prevdiff = nums[1] - nums[0];
        int result = prevdiff != 0 ? 2 : 1;
        for (int i = 2; i < len; ++i) {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
                ++result;
                prevdiff = diff;
            }
        }

        return result;
    }
};
```

