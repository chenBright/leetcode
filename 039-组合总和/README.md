# 039-组合总和

## 题目

leetcode：[039-组合总和](https://leetcode-cn.com/problems/combination-sum/)

## 回溯法

使用`DFS`和`BFS`都可以解决（从target的角度看）。

### DFS

先对数组排序，从大的先开始匹配且尽可能多匹配。

```c++
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int length = candidates.size();
        if (length == 0) {
            return res;
        }

        sort(candidates.begin(), candidates.end(), compare); // 降序

        int low = 0;
        // 跳过值比 target 大的元素
        while (low < length) {
            if (candidates[low] <= target) {
                break;
            }
            ++low;
        }

        vector<int> temp;
        combinationSum(candidates, temp, 0, target);

        return res;
    }

    static bool compare(int a, int b) {
        return a > b;
    }

private:
    vector<vector<int> > res;

    void combinationSum(vector<int> &candidates, vector<int> resTemp, int index, int target) {
        if (target == 0) {
            res.push_back(resTemp);
            return;
        }

        if (target < 0 || index >= candidates.size()) {
            return;
        }

        int candidate = candidates[index];
        int num = target / candidate; // 最多能有几个 candidate
        for (int i = 0; i <= num; ++i) {
            if (i != 0) {
                resTemp.push_back(candidate);
            }
            combinationSum(candidates, resTemp, index + 1, target - candidate * i);
        }
    }
};
```

### BFS

先对数组排序，从大的先开始匹配但***[low … high]***中每个都匹配一次。

```c++
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        int length = candidates.size();
        if (length == 0) {
            return res;
        }

        sort(candidates.begin(), candidates.end(), compare); // 降序

        int low = 0;
        while (low < length) {
            if (candidates[low] <= target) {
                break;
            }
            ++low;
        }

        vector<int> temp;
        combinationSum(candidates, temp, low == length ? length - 1 : low, length - 1, target);

        return res;
    }

    static bool compare(int a, int b) {
        return a > b;
    }

private:
    vector<vector<int> > res;

    void combinationSum(vector<int> &candidates, vector<int> &resTemp, int low, int high, int target) {
        if (target == 0) {
            res.push_back(resTemp);
            return;
        } else if (target < 0 || low > high) {
            return;
        }

        // [low ... high]中每个元素都匹配一次
        for (int i = low; i <= high; ++i) {
            resTemp.push_back(candidates[i]);
            combinationSum(candidates, resTemp, i, high, target - candidates[i]);
            resTemp.pop_back();
        }
    }
};
```

