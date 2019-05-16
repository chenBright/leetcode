# 216-组合总和 III

## 题目

leetcode：[216-组合总和 III](https://leetcode-cn.com/problems/combination-sum-iii/)

## 回溯法

与[”039-组合总和“方法](../039-组合总和/)类似，只是约束添加有一点不同。使用`DFS`和`BFS`都可以解决（从n的角度看）。

## BFS

```c++
class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        if (k <= 0) {
            return res;
        }

        // 生成数字
        for (int i = 1; i <= 9; ++i) {
            nums.push_back(i);
        }

        combinationSum3(k, n,  0);

        return res;
    }

private:
    vector<int> nums;
    vector<int> resTemp;
    vector<vector<int> > res;

    void combinationSum3(int k, int n, int index) {
        if (k == 0 && n == 0) {
            res.push_back(resTemp);
            return;
        } else if (k < 0 || n < 0) {
            return;
        }

        for (int i = index; i < nums.size() && n - nums[i] >= 0; ++i) {
            resTemp.push_back(nums[i]);
            combinationSum3(k - 1, n - nums[i], i + 1);
            resTemp.pop_back();
        }
    }
};
```

### BFS

```c++
class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        if (k <= 0) {
            return res;
        }

        // 生成数字
        for (int i = 1; i <= 9; ++i) {
            nums.push_back(i);
        }

        combinationSum3(k, n,  0);

        return res;
    }

private:
    vector<int> nums;
    vector<int> resTemp;
    vector<vector<int> > res;

    void combinationSum3(int k, int n, int index) {
        if (k == 0 && n == 0) {
            res.push_back(resTemp);
            return;
        } else if (k < 0 || n < 0 || index >= nums.size() || n - nums[index] < 0) {
            return;
        }

        combinationSum3(k, n, index + 1);

        resTemp.push_back(nums[index]);
        combinationSum3(k - 1, n - nums[index], index + 1);
        resTemp.pop_back();
    }
};
```



