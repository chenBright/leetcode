# 260-只出现一次的数字 III

## 题目

leetcode：[260-只出现一次的数字 III](https://leetcode-cn.com/problems/single-number-iii/)

## 使用HashMap记录字符出现次数

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        vector<int> result;
        unordered_map<int, int> m;
        for (const auto &num : nums) {
            if (m.count(num)) {
                m[num]++;
            } else {
                m[num] = 1;
            }
        }

        for (const auto &num : nums) {
            if (m[num] == 1) {
                result.push_back(num);
            }
        }

        return result;
    }
};
```

## 位运算

参考[博客](https://github.com/grandyang/leetcode/issues/260) 和[LeetCode mbinary 的思路](https://leetcode-cn.com/problems/single-number-iii/comments/9251)。

假设只出现一次的数字分别为`a`、`b`，`c = a ^ b`。

如果能将`a`、`b`分别分到两组，且出现两次的数字成组分到同一组中，则每一组分别将组中所有数字进行异或操作，则能求出`a`、`b`。分组需要考虑两个问题：

- 将出现两次的数字分到同一组：只要将数组中的数字与同一数字（`c &= -c`）与（`&`），等于0的分到一组，不等于0的分到一组。***注***：可能会出现一组中只有一个数字的情况，该数字是`a`或`b`。
- 将`a`和`b`分到两个不同的组中：将所有数组异或一次，得到的结果实际等于只出现一次的两个数字异或的结果`c`。`c`中某个非0位（如最低非0位），如果`a`中对应的为1，则`b`中对应的位一定为0。令`c &= -c`（`-c`的二进制是`c`的二进制的反码加1），此时`c`只有一位为1，对应原`c`中的最低非0位，其他为都为0。最后，`a & c = 1`、`b & c = 0`，则将`a`、`b`分到了不同的组。

假设`c = 110(2)`，则`-c = 010`，`c & -c = 010`。

时间复杂度：***O(n)***。

空间复杂度：***O(n)。***

```c++
class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>()); // 逐一异或
        vector<int> result(2, 0);
        diff &= -diff; // 取最低非0位
        for (const auto &num : nums) {
            // 分组
            if (num & diff) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }

        return result;
    }
};
```

