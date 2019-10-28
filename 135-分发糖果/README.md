# 135-分发糖果

## 题目

leetcode：[135-分发糖果](https://leetcode-cn.com/problems/candy/)

## 蛮力法

参考[LeetCode官方题解方法一](https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode/)。

时间复杂度：***O(n^2)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    int candy(vector<int> &ratings) {
        int length = ratings.size();
        vector<int> candies(length, 1);
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < length; ++i) {
                if (i < length - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    flag = true;
                }
                // 更新
                if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    flag = true;
                }
            }
        }
        
        int result = 0;
        for (const auto &candy : candies) {
            result += candy;
        }

        return result;
    }
};
```

## 贪心算法

### 两个数组

参考[LeetCode官方题解方法二](https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode/。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    int candy(vector<int> &ratings) {
        int length = ratings.size();
        vector<int> left2right(length, 1);
        vector<int> right2left(length, 1);
        // 更新与左边孩子的关系
        for (int i = 1; i < length; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left2right[i] = left2right[i - 1] + 1;
            }
        }

        // 更新与右边孩子的关系
        for (int j = length - 2; j >= 0; --j) {
            if (ratings[j] > ratings[j + 1]) {
                right2left[j] = right2left[j + 1] + 1;
            }
        }

        int result = 0;
        for (int k = 0; k < length; ++k) {
            // 取最大值才满足条件
            result += max(left2right[k], right2left[k]);
        }

        return result;
    }
};
```

### 一个数组

参考[LeetCode官方题解方法二](https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode/)。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    int candy(vector<int> &ratings) {
        int length = ratings.size();
        vector<int> candies(length, 1);

        // 更新与左边孩子的关系
        for (int i = 1; i < length; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int j = length - 2; j >= 0; --j) {
            if (ratings[j] > ratings[j + 1]) {
                // 取最大值才满足条件
                candies[j] = max(candies[j], candies[j + 1] + 1);
            }
        }

        int result = 0;
        for (const auto &candy : candies) {
            result += candy;
        }

        return result;
    }
};
```

### 不需要数组

参考[博客](https://github.com/grandyang/leetcode/issues/135)。

时间复杂度：***O(n)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty()) {
            return 0;
        }

        int length = ratings.size();
        int result = 1;
        int previous = 1; // 连续递减序列的最大值
        int count = 0; // 连续递减序列的长度
        for (int i = 1; i < length; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                if (count > 0) {
                    // previous - count - count - 1 - ... - 1
                    result += count * (count + 1) / 2;
                    if (count >= previous) {
                        // 连续递减序列的最大值应该为 count，将加少了的补上
                        result += count - previous + 1;
                    }
                    previous = 1;
                    count = 0;
                }
                // ratings[i] <= ratings[i - 1]
                previous = (ratings[i] == ratings[i - 1]) ? 1 : previous + 1;
                result += previous;
            } else { // 统计连续递减序列的长度
                ++count;
            }
        }
        if (count > 0) {
            result += count * (count + 1) / 2;
            if (count >= previous) {
                result += count - previous + 1;
            }
        }

        return result;
    }
};
```

