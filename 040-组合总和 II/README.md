# 040-组合总和 II

## 题目

leetcode：[040-组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/)

## BFS回溯法

使用***BFS***（从target的角度看）回溯法，同时去重。

假设***[low + 1 … high]***能找到一个和为`target`，且此区间有几个元素等于`candidates[low]`。

此时，***[low … high]***中元素等于`candidates[low]`的个数比***[low + 1 … high]***中多。所以，对于"包含`candidates[low]`的解中"，***[low … high]***一定包含***[low + 1 … high]***，只需要求一次即可。

```c++
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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
        } else if (target < 0) {
            return;
        }        

        // BFS（从target角度看）
        for (int i = low; i <= high && candidates[i] <= target; ++i) {
            /**
             * i == low 肯定取，表示至少取1个 。
             * 如果candidates[low] == candidates[low - 1]，
             * [low ... high] 包含了 [low - 1 ... high] 的结果，所以跳过，达到去重的效果
             */
            if (i != low && candidates[i] == candidates[i - 1]) {
                continue;
            }
            resTemp.push_back(candidates[i]);
            combinationSum(candidates, resTemp, i + 1, high, target - candidates[i]);
            resTemp.pop_back();
        }
    }
};
```

