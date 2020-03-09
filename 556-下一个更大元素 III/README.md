# 556-下一个更大元素 III

## 题目

leetcode：[556-下一个更大元素 III](https://leetcode-cn.com/problems/next-greater-element-iii/)

## 下一个排列

该题的思路和[031-下一个排列](./031-下一个排列/README.md)一样。

```c++
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);

        int length = str.size();
        int i = length - 2;
        while (i >= 0 && str[i] >= str[i + 1]) {
            --i;
        }

        if (i < 0) {
            return -1;
        }

        for (int j = length - 1; j >= 0; --j) {
            if (str[j] > str[i]) {
                swap(str[j], str[i]);
                sort(str.begin() + i + 1, str.end());
                break;
            }
        }

        // 小心整型溢出
        long result = stol(str);

        return result > INT_MAX ? -1 : result;
    }
};
```

直接使用 STL 中的 `next_permutation`函数。

```c++
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);

        next_permutation(str.begin(), str.end());

        // 小心整型溢出
        long result = stol(str);

        return result > INT_MAX ? -1 : result;
    }
};
```

