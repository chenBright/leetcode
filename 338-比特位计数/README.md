# 338-比特位计数

## 题目

leetcode：[338-比特位计数](https://leetcode-cn.com/problems/counting-bits/)

## 遍历每一个数字，统计位

遍历`[0, num]`，计算每个数字的`bit 1`。计算`bit 1`的方法参考[191-位1的个数](./191-位1的个数/README.md)。

时间复杂度：***O(n \* sizeof(integer))***。

```c++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        for (int i = 0; i <= num; ++i) {
            result[i] = bits(i);
        }

        return result;
    }

private:
    int bits(int num) {
        int count = 0;
        while (num) {
            num &= num - 1; // 快速移除最右边的 bit 1
            ++count;
        }

        return count;
    }
};
```

## bitset

使用`bitset`计算每个数字的`bit 1`。

时间复杂度：***O(n \* sizeof(integer))***。

空间复杂度：***O(n \* sizeof(integer))***。

```c++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        for (int i = 0; i <= num; ++i) {
            result[i] = bitset<32>(i).count();
        }

        return result;
    }
};
```

## 动态规划

参考[LeetCode官方题解](https://leetcode-cn.com/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode/)。

时间复杂度：***O(n)***。

### 高位有效

```c++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        int i = 0;
        int b = 1;
        while (b <= num) {
            // 计算区间 [b, 2b)（因为 i < b）或者 [b, num)
            while (i < b && i + b <= num) {
                // 区间 [b, 2b) 的结果可通过 [0, b) 的结果求出
                // dp[i + b] = dp[i] + 1，其中 i < b = 2 ^ m
                result[i + b] = result[i] + 1;
                ++i;
            }
            i = 0;
            b <<= 1;
        }

        return result;
    }
};
```

### 低位有效

```c++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        int i = 0;
        int b = 1;
        for (int i = 1; i <= num; ++i) {
            // result[i] = result[i / 2] + (i % 2);
            result[i] = result[i >> 1] + (i & 1);
        }

        return result;
    }
};
```

### 最后设置位

因为***i & (i - 1) 可以快速移除最右边的 bit 1***，所以***i 比 i & (i - 1) 多一位 1***。

```c++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        int i = 0;
        int b = 1;
        for (int i = 1; i <= num; ++i) {
            // i & (i - 1) 可以快速移除最右边的 bit 1，
            // 即 i 比 i & (i - 1) 多一位 1。
            result[i] = result[i & (i - 1)] + 1;
        }

        return result;
    }
};
```

