# 047-全排列 II

## 题目

leetcode：[047-全排列 II](https://leetcode-cn.com/problems/permutations-ii/)

## 回溯法

存在重复数字的序列需要考虑去重。

### Set

使用`Set`的特性去重。代码略。

### 拷贝的实现

在[046-全排列 实现1](../046-全排列/permute_backtracking1.cpp)的基础上，增加排序和去重部分。

```c++
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        if (nums.empty()) {
            return result;
        }

        permuteUniqueRecursion(nums);

        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmpResult;
    void permuteUniqueRecursion(vector<int> &nums) {
        if (nums.empty()) {
            result.push_back(tmpResult);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) { // 去重：该位置上已经有相同的数字了，跳过
                continue;
            }
            vector<int> tmp(nums);
            tmp.erase(tmp.begin() + i);
            tmpResult.push_back(nums[i]);
            permuteUniqueRecursion(tmp);
            tmpResult.pop_back();
        }
    }
};
```

### 用`visited`数组记录访问过的元素

在[046-全排列 实现2](../046-全排列/permute_backtracking2.cpp)的基础上，增加排序和去重部分。

```c++
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        if (nums.empty()) {
            return result;
        }

        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        permuteUniqueRecursion(nums, 0, visited);

        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmpResult;
    void permuteUniqueRecursion(vector<int> &nums, int level, vector<bool> &visited) {
        if (level == nums.size()) {
            result.push_back(tmpResult);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            if (i != 0 && nums[i] == nums[i - 1] && !visited[i - 1]) { // 去重：该位置上已经有相同的数字了，跳过
                continue;
            }

            visited[i] = true;
            tmpResult.push_back(nums[i]);
            permuteUniqueRecursion(nums, level + 1, visited);
            tmpResult.pop_back();
            visited[i] = false;
        }
    }
};
```

## STL next_permutation函数

注意：`next_permutation`函数要求输入序列为有序。

```c++

```

