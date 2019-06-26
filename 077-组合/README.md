# 077-组合

## 题目

leetcode：[077-组合](https://leetcode-cn.com/problems/combinations/)


## 回溯法

### 拷贝

基于[046-全排列 实现1](../046-全排列/permute_backtracking1.cpp)。

```c++
class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        if (nums.empty()) {
            return result;
        }

        permuteRecursion(nums);

        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmpResult;

    void permuteRecursion(vector<int> &nums) {
        if (nums.empty()) {
            result.push_back(tmpResult);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            vector<int> tmp(nums);
            tmp.erase(tmp.begin() + i);
            tmpResult.push_back(nums[i]);
            permuteRecursion(tmp);
            tmpResult.pop_back();
        }
    }
};
```

### 非拷贝

因为

- 按照题目要求，序列中无重复数组；
- 组合问题，每次组合只需要考虑后面的数字即可；

综上，不需要临时数组拷贝，使用两个变量表示待选数字的范围即可。

```c++
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        if (n == 0 || k == 0) {
            return result;
        }

        combineRecursion(1, n, k);

        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmpResult;

    void combineRecursion(int start, int end, int k) {
        if (tmpResult.size() >= k) {
            result.push_back(tmpResult);
            return;
        }

        if (end - start + 1 < k - tmpResult.size()) {
            return;
        }

        for (int i = start; i <= end; ++i) {
            tmpResult.push_back(i);
            combineRecursion(i + 1, end, k);
            tmpResult.pop_back();
        }
    }
};
```

## 字典序

参考[LeetCode官方题解](https://leetcode-cn.com/problems/combinations/solution/zu-he-by-leetcode)。

有一个地方还是不太明白：

```c++
tmp[j] = j + 1;
```

代码如下：

```c++
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if (n == 0 || k == 0) {
            return result;
        }

        vector<int> tmp(k + 1);
        for (int i = 0; i < k; ++i) {
            tmp[i]= i + 1; 
        }
        tmp[k] = n + 1; // 哨兵

        int j = 0;
        while (j < k) {
            result.push_back(vector<int>(tmp.begin(), tmp.end() - 1));

            j = 0;
            while (j < k && tmp[j] + 1 == tmp[j + 1]) {
                tmp[j] = j + 1; // TODO 不懂
                ++j;
            }
            ++tmp[j];
        }

        return result;
    }
};
```

## 迭代

参考[博客 解法三](https://www.cnblogs.com/grandyang/p/4332522.html)和[LeetCode上windliang的题解 解法四]()

从数字小的组合开始递增。

```c++
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if (n == 0 || k == 0) {
            return result;
        }

        vector<int> tmp(k, 0);

        int i = 0;
        while (i >= 0) {
            ++tmp[i];
            if (tmp[i] > n) {
                --i;
            } else if (i == k - 1) {
                result.push_back(tmp);
            } else {
                ++i;
                tmp[i] = tmp[i - 1]; // 等到下一循环，右边数字至少是左边数字 + 1
            }
        }

        return result;
    }
};
```

