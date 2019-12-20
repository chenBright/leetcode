# 136-只出现一次的数字

## 题目

leetcode：[136-只出现一次的数字](https://leetcode-cn.com/problems/single-number/)

## 思路

1. 遍历字符串，记录每个字符出现的次数。

2. 遍历字符串，查找第一个只出现一次的字符，并返回其位置。

## 使用map记录字符出现次数

步骤1的时间复杂度为**O(n)**。步骤2中，遍历字符串的时间复杂度为**O(n)**，map底层是用红黑树实现的，查找字符的时间复杂度为**O(logn)**，步骤1的时间复杂度为**O(nlogn)**。

该方法的时间复杂度为**O(nlogn)**。

```c++
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }

        map<int, int> m;
        auto it = nums.begin();
        while (it != nums.end()) {
            if (m.count(*it)) {
                ++m[*it];
            } else {
                m[*it] = 1;
            }
            ++it;
        }

        it = nums.begin();
        while (it != nums.end()) {
            if (m[*it] == 1) {
                return *it;
            }
            ++it;
        }

        return -1;
    }
};
```

## 使用哈希表记录字符出现的次数

哈希表查找字符的时间复杂度为**O(1)**，所以该方法的时间复杂度为**O(n)**。

`unordered_map`的底层实现是哈希表。

```c++
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }

        unordered_map<int, int> m;
        auto it = nums.begin();
        while (it != nums.end()) {
            if (m.count(*it)) {
                ++m[*it];
            } else {
                m[*it] = 1;
            }
            ++it;
        }

        it = nums.begin();
        while (it != nums.end()) {
            if (m[*it] == 1) {
                return *it;
            }
            ++it;
        }

        return -1;
    }
};
```

## 异或

异或：相同为0，不同为1。异或同一个数两次，原数不变。例如：

```c++
2 ^ 1 = 3
3 ^ 2 = 1
```

题目刚好可以使用异或的这个特性：***除了某个元素只出现一次以外，其余每个元素均出现两次***。

该方法的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (const auto& n : nums) {
            result ^= n;
        }

        return result;
    }
};
```

## 数学方法

根据题目的规律——***除了某个元素只出现一次以外，其余每个元素均出现两次***。可以使用以下公式计算得到只出现一次的元素：

`2 * (a + b + c) - (a + a + b + b + c) = c`

`set`和`vector`遍历的时间复杂度都为***O(n)***，则该方法的时间复杂度为***O(n + n) = O(n)***。

```c++
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return 2 * accumulate(s.begin(), s.end(), static_cast<long>(0)) - accumulate(nums.begin(), nums.end(), static_cast<long>(0));
    }
};
```

