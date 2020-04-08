# 274-H指数

## 题目

leetcode：[274-H指数](https://leetcode-cn.com/problems/h-index/)

## 思路

参考[维基百科中H指数](https://zh.wikipedia.org/wiki/H指数)中的方法：

```shell
1. 将其发表的所有SCI论文按被引次数从高到低排序；
2. 从前往后查找排序后的列表，直到某篇论文的序号大于该论文被引次数。所得序号减一即为H指数。
```

## 基于比较的排序

时间复杂度：**O(nlogn)**。

空间复杂度：**O(1)**。

```c++
class Solution {
public:
    int hIndex(vector<int> &citations) {
        sort(citations.begin(), citations.end(), greater<int>());

        // i + 1：文章数
        for (int i = 0; i < citations.size(); ++i) {
            if (i + 1 > citations[i]) {
                return i;
            }
        }

        return citations.size();
    }
};
```

## 计数排序

参考[LeetCode官方题解](https://leetcode-cn.com/problems/h-index/solution/hzhi-shu-by-leetcode)。

时间复杂度：**O(nlogn)**。

空间复杂度：**O(n)**。

```c++
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        vector<int> papers(n + 1, 0); // paper[i]：引用数为 i 的文章数
        for (const auto &c : citations) {
            ++papers[min(n, c)];
        }

        int citation = n; // 引用数
        // count：文章数
        for (int count = papers[citation]; citation > count; count += papers[citation]) {
            --citation;
        }

        return citation;
    }
};
```

