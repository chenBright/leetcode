# 046-全排列

## 题目

leetcode：[046-全排列](https://leetcode-cn.com/problems/permutations/)

## 回溯法

下面得***实现1~3***的共同思想都是：剩下为排列的数字都在此位置上排一次，形成一个序列。

### 实现1

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
            tmp.erase(tmp.begin() + i, tmp.begin() + i + 1);
            tmpResult.push_back(nums[i]);
            permuteRecursion(tmp);
            tmpResult.pop_back();
        }
    }
};
```

### 实现2

以下几种方法都是参考[博客](https://www.cnblogs.com/grandyang/p/4358848.html)的。

用`visited`数组记录访问过的元素，就不需要想实现1一样拷贝数组。

```c++
class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        if (nums.empty()) {
            return result;
        }

        vector<bool> visited(nums.size(), false);
        permuteRecursion(nums, 0, visited);

        return result;
    }

private:
    vector<vector<int> > result;
    vector<int> tmpResult;

    void permuteRecursion(vector<int> &nums, int level, vector<bool> &visited) {
        if (level == nums.size()) {
            result.push_back(tmpResult);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            tmpResult.push_back(nums[i]);
            permuteRecursion(nums, level + 1, visited);
            tmpResult.pop_back();
            visited[i] = false;
        }
    }
};
```

### 实现3

让未排列的元素交换到当前位置上都排一次。

```c++
class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        if (nums.empty()) {
            return result;
        }

        permuteRecursion(nums, 0);

        return result;
    }

private:
    vector<vector<int> > result;

    void permuteRecursion(vector<int> &nums, int start) {
        if (start >= nums.size()) {
            result.push_back(nums);
        }

        for (int i = start; i < nums.size(); ++i) {
            // 是后面的数字都在 start 位置上排一次
            swap(nums[start], nums[i]);
            permuteRecursion(nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
};
```

### 实现4

在前面已经排列好的序列的基础上插入，有`n+1`个位置。

```c++
class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        if (nums.empty()) {
            return vector<vector<int> >(1, vector<int>());
        }

        vector<vector<int> > result;
        int first = nums[0];
        nums.erase(nums.begin());
        vector<vector<int> > words = permute(nums);
        for (auto &word : words) {
            // 插入到 word.size() + 1 个位置上
            for (int i = 0; i <= word.size(); ++i) {
                word.insert(word.begin() + i, first);
                result.push_back(word);
                word.erase(word.begin() + i);
            }
        }

        return result;
    }
};
```

## STL next_permutation

注意：`next_permutation`函数要求输入序列为有序。

```c++
class Solution {
public:
    vector<vector<int> > permute(vector<int> &nums) {
        vector<vector<int> > result;
        if (nums.empty()) {
            return result;
        }

        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end()); // next_permutation 要求输入序列为有序
        do {
            result.push_back(tmp);
        } while (next_permutation(tmp.begin(), tmp.end()));

        return result;
    }
};
```

