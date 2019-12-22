# 137-只出现一次的数字 II

## 题目

leetcode：[137-只出现一次的数字 II](https://leetcode-cn.com/problems/single-number-ii/)

## 思路

以下三种方法的思路同[136-只出现一次的数字](../136-只出现一次的数字/)。

## 使用map记录字符出现次数

```c++
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i])) {
                ++m[nums[i]];
            } else {
                m[nums[i]] = 1;
            }
        }

        for (const auto &n : m) {
            if (n.second == 1) {
                return n.first;
            }
        }

        return -1;
    }
};
```

## 使用哈希表记录字符出现的次数

```c++
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i])) {
                ++m[nums[i]];
            } else {
                m[nums[i]] = 1;
            }
        }

        for (const auto &n : m) {
            if (n.second == 1) {
                return n.first;
            }
        }

        return -1;
    }
};
```

## 数学方法

`3 * (a + b + c) - (a + a + a + b + b + b + c) = 2c`

```c++
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        long sum1 = 3 * accumulate(s.begin(), s.end(), static_cast<long>(0));
        long sum2 = accumulate(nums.begin(), nums.end(), static_cast<long>(0));
        return (sum1 - sum2) / 2;
    }
};
```

## 位运算

参考[Single Number II（模拟三进制法，图表解析）](https://leetcode-cn.com/problems/single-number-ii/solution/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/)
