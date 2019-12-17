# 078-子集

## 题目

leetcode：[078-子集](https://leetcode-cn.com/problems/subsets/)

## DFS回溯法

```c++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmpResult;
        subsetsRecursion(nums, result, tmpResult, 0);

        return result;
    }

private:
    void subsetsRecursion(vector<int>& nums, vector<vector<int>>& result, vector<int>& tmpResult, int index) {
        if (index == nums.size()) {
            result.push_back(tmpResult);
            return;
        }

        // 不取当前数字
        subsetsRecursion(nums, result, tmpResult, index + 1);

        // 取当前数字
        tmpResult.push_back(nums[index]);
        subsetsRecursion(nums, result, tmpResult, index + 1);
        tmpResult.pop_back();
    }
};
```

## BFS回溯法

```c++
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> tmpResult;
        subsets(nums, result, tmpResult, 0);

        return result;
    }

private:
    void subsets(vector<int>& nums, vector<vector<int> >& result, vector<int>& tmpResult, int index) {
        if (index == nums.size()) {
            result.push_back(tmpResult);
            return;
        }

        // 先不考虑后面的元素，先将当前集合当做子集添加当前集合。
        result.push_back(tmpResult);
        // 与后面每个元素分别组成一个集合，例如
        // tmpResult = [1]，则组成两个集合：
        // [1, 2]、[1, 3]。
        for (int i  = index; i < nums.size(); ++i) {
            tmpResult.push_back(nums[i]);
            subsets(nums, result, tmpResult, ++index);
            tmpResult.pop_back();
        }
    }
};
```

## 迭代

遍历数组，每遇到一个数字，将其与已加入结果中的集合组合，并将它们加入到结果中。

```c++
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;

        result.push_back(vector<int>()); // 空集合
        for (int i = 0; i < nums.size(); ++i) {
            int resultLength = result.size();
            // 当前数字与已经存在的子集组合成新的组合，并将其加入到结果中。
            for (int j = 0; j < resultLength; ++j) {
                auto tmp = result[j];
                tmp.push_back(nums[i]);
                result.push_back(tmp);
            }
        }

        return result;
    }
};
```

## 位运算

参考[LeetCode 评论区 WangYu  的实现](https://leetcode-cn.com/problems/subsets/comments/21473)。

数组 `[1,2,3]` 的子集也就是其中的三个元素取与不取的组合。把它想象为二进制的三个 bit 位 `1 1 1`，那么从 `0 0 0` 到 `1 1 1` 的 8 个数，就构成了所有子集的选取情况。比如 `0 0 1`表示取第1个元素，`0 1 1` 表示取前两个元素。

```c++
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        int length = nums.size();

        result.push_back(vector<int>()); // 空集合

        // 每个数字代表一个位，有两种情况（取或不取），总共 2 ^ length 中情况
        int subLength = pow(2, length);
        // 当前取数情况，如果 nums = [1, 2, 3]，则当前 hash = 001(2)
        int hash = 1;
        while (hash < subLength) {
            vector<int> tmp;
            for (int i = 0; i < length; ++i) {
                // 表示是否取第 i 位，1 表示取，0 表示不取。
                // 每次向左移1位。
                int a = 1 << i;
                if (a & hash) {
                    tmp.push_back(nums[i]);
                }
            }
            result.push_back(tmp);
            ++hash;
        }

        return result;
    }
};
```

