# 078-子集

## 题目

leetcode：[078-子集](https://leetcode-cn.com/problems/subsets/)


## BFS回溯法

```c++
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return res;
        }
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
        // 与后面没个元素分别组成一个集合
        for (int i = left; i <= right; ++i) {
            temp.push_back(nums[i]);
            subsets(nums, i + 1, right);
            temp.pop_back();
        }
    }
};
```

## 迭代

遍历数组，每遇到一个数字，将其与已加入结果中的集合组合，并加入到结果中。

```c++
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > res;
        int length = nums.size();
        if (length == 0) {
            return res;
        }

        res.push_back(vector<int>()); // 空集合
        for (int i = 0; i < length; ++i) {
            vector<int> temp;
            int resLength = res.size();
            // 当前数字与已经存在的集合组合
            for (int j = 0; j < resLength; ++j) {
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

## 位运算

参考[LeetCode 评论区 WangYu  的实现](https://leetcode-cn.com/problems/subsets/comments/21473)。

数组 `[1,2,3]` 的子集也就是其中的三个元素取与不取的组合。把它想象为二进制的三个 bit 位 `1 1 1`，那么从 `0 0 0` 到 `1 1 1` 的 8 个数，就构成了所有子集的选取情况。比如 `0 0 1`表示取第1个元素，`0 1 1` 表示取前两个元素。

```c++
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > res;
        int length = nums.size();
        if (length == 0) {
            return res;
        }

        res.push_back(vector<int>()); // 空集合
        
        // 每个数字代表一个位，有两种情况（取或不取），总共 2 ^ length 中情况
        int subLength = pow(2, length); 
        int hash = 1; // 当前取数情况
        while (hash < subLength) {
            vector<int> temp;
            for (int i = 0; i < length; ++i) {
                int a = 1 << i; // 表示第 i 位，每次想左移1位
                if (a & hash) {
                    temp.push_back(nums[i]);
                }
            }
            res.push_back(temp);
            ++hash;
        }

        return res;
    }
};
```

