# 268-缺失数字

## 题目

leetcode：[268-缺失数字](https://leetcode-cn.com/problems/missing-number/)

## 排序

先排序，再找缺失的数字。

- 判断`n`是否出现在末位，如果`nums[nums.size() - 1] != nums.size()`，则返回`n`；
- 判断`0`是否出现在首位，如果`nums[0] != 0`，则返回`0`；
- 如果`nums[i] + 1 != nums[i + 1]`，则返回`i + 1`。

时间复杂度：***O(nlogn)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        if (nums[nums.size() - 1] != nums.size()) { // 判断 n 是否出现在末位
            return nums.size();
        } else if (nums[0] != 0) { // 判断 0 是否出现在首位
            return 0;
        }

        for (int i = 0; i + 1 < nums.size(); ++i) {
            int expectedNum = nums[i] + 1;
            if (expectedNum != nums[i + 1]) {
                return expectedNum;
            }
        }

        return -1; // 未缺失任何数字（保证函数有返回值）
    }
};
```

## 哈希表

使用数组当做哈希表，记录`0 ... n`是否出现，再遍历哈希表，找出缺失的数字。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        vector<bool> m(nums.size() + 1, false); // 记录 0 ... n 的数字是否出现
        for (const auto &num : nums) {
            m[num] = true;
        }

        for (int i = 0; i < m.size(); ++i) {
            if (!m[i]) {
                return i;
            }
        }

        return -1; // 未缺失任何数字（保证函数有返回值）
    }
};
```

## 位运算

参考[LeetCode官方题解方法三](https://leetcode-cn.com/problems/missing-number/solution/que-shi-shu-zi-by-leetcode)。

使用异或的思想，将数组中的所有数字和`0 ... n`进行异或操作。除了缺失的数字，其他数字出现了两次，最后异或的操作等于缺失的数字。

时间复杂度：***O(nlogn)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int missing = nums.size(); // n
        for (int i = 0; i < nums.size(); ++i) {
            // i 的值：[0, n - 1]
            // nums[i] 的值：[0 ... missing - 1]、[missing + 1, n]
            missing ^= i ^ nums[i];
        }

        return missing;
    }
};
```

## 数学

使用公式：`0 + 1 + 2 + ... + n - sum(nums)`。其中`0 + 1 + 2 + ... + n = n * (n + 1) / 2`。

时间复杂度：***O(n)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int expectedSum = nums.size() * (nums.size() + 1) / 2;
        int actualSum = 0;
        for (const auto &num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};
```

