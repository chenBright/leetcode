# 494-目标和

## 题目

leetcode：[494-目标和](https://leetcode-cn.com/problems/target-sum/)

## 思路

参考[博客](https://github.com/grandyang/leetcode/issues/494)。

## DFS

### 实现1

```c++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int result = 0;
        dfs(nums, S, 0, 0, result);

        return result;
    }
private:
    void dfs(vector<int>& nums, int S, int sum, int index, int& result) {
        if (index == nums.size()) {
            if (sum == S) {
                ++result;
            }

            return;
        }

        dfs(nums, S, sum + nums[index], index + 1, result);
        dfs(nums, S, sum - nums[index], index + 1, result);
    }
};
```

### 实现2

```c++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, S, 0, 0);
    }
private:
    int dfs(vector<int>& nums, int S, int sum, int index) {
        if (index == nums.size()) {
            return sum == S ? 1 : 0;
        }

        return dfs(nums, S, sum + nums[index], index + 1) + dfs(nums, S, sum - nums[index], index + 1);
    }
};
```

## 动态规划

### 递归

```c++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<long, long> > dp(nums.size());
        return dfs(nums, S, 0, dp);
    }
private:
    long dfs(vector<int>& nums, int S, int index, vector<unordered_map<long, long> >& dp) {
        if (index == nums.size()) {
            return S == 0 ? 1 : 0;
        }

        if (dp[index].count(S) != 0) {
            return dp[index][S];
        }

        dp[index][S] = dfs(nums, S - nums[index], index + 1, dp) + dfs(nums, S + nums[index], index + 1, dp);

        return dp[index][S];
    }
};
```

### 迭代

```c++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int length = nums.size();
        vector<unordered_map<long, long> > dp(length + 1);

        dp[0][0] = 1;

        for (int i = 0; i < length; ++i) {
            for (const auto& it : dp[i]) {
                int sum = it.first;
                int count = it.second;
                dp[i][sum + nums[i]] += count;
                dp[i][sum - nums[i]] += count; 
            }
        }

        return dp[length][S];
    }
};
```

