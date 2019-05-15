# 090-子集 II

## 题目

leetcode：[090-子集 II](https://leetcode-cn.com/problems/subsets-ii/)


## DFS回溯法

使用***DFS回溯法***，参考[078-子集 DFS回溯法](../078-子集/subsets_bfs.cpp)。

去重，则参考[040-组合总和 II](../040-组合总和 II)。

使用***BFS***（从target的角度看）回溯法，同时去重。

假设***[low + 1 … high]***区间有几个元素等于`nums[low]`，则***[low … high]***中元素等于`nums[low]`的个数比***[low + 1 … high]***中多。所以，对于"包含`nums[low]`的解中"，***[low … high]***一定包含***[low + 1 … high]***，只需要求一次即可。

```c++
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return res;
        }

        sort(nums.begin(), nums.end());
        subsets(nums, 0, length - 1);

        return res;
    }

private:
    vector<vector<int> > res;
    vector<int> temp;

    void subsets(vector<int> &nums, int left, int right) {
        if (left > right) {
            res.push_back(temp);
            return;
        }

        res.push_back(temp); // 先不考虑后面的元素，先添加当前集合
        // 与后面每个元素分别组成一个集合
        for (int i = left; i <= right; ++i) {
            /**
             * i == low 肯定取，表示至少取1个 。
             * 如果nums[low] == nums[low - 1]，
             * [low ... high] 包含了 [low - 1 ... high] 的结果，所以跳过，达到去重的效果
             */
            if (i != left && nums[i] == nums[i - 1]) {
                continue;
            }
            temp.push_back(nums[i]);
            subsets(nums, i + 1, right);
            temp.pop_back();
        }
    }
};
```

## 迭代

迭代的方法，主要参考[078-子集 迭代法](../078-子集/subsets.cpp)。

去重的思想：每遇到一个数字，

- 如果该数字与前一个数字相等，则只需要与前一个数字生成的子集组合即可。与其他的子集组合的结果已经在处理前一个数字的时候生成了。
- 否则，与所有已生成的子集组合。

所以，需要每次记录上一次生成子集的数量，用来确定下一次组合的起点。参考[LeetCode 评论区 宝宝可乖了 的思路](https://leetcode-cn.com/problems/subsets-ii/comments/39147)。

```c++
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        vector<vector<int> > res;
        int length = nums.size();
        if (length == 0) {
            return res;
        }

        sort(nums.begin(), nums.end());

        int left = 0; // 生成子集的起点
        int right = 1; // 生成子集的终点
        int subsetsLen = 0; // 生成子集的数量
        res.push_back(vector<int>()); // 空集合
        for (int i = 0; i < length; ++i) {
            int resLength = res.size();
            if (i != 0 && nums[i] == nums[i - 1]) { // 如果数字与前一个数字相等，则至于上次生成的子集组合
                left = resLength - subsetsLen;
            } else {
                left = 0;
            }
            right = resLength;
            subsetsLen = right - left; // 这次生成的子集的数量
            vector<int> temp;
            // 组合
            for (int j = left; j < right; ++j) {
                temp.clear();
                temp.assign(res[j].begin(), res[j].end());
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }

        return res;
    }
};
```

