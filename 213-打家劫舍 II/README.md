# 213-打家劫舍 II

## 题目

leetcode：[213-打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/)

## 动态规划

这道题在[198-打家劫舍](https://leetcode-cn.com/problems/house-robber/)基础上加了一点约束：如果偷了第一间，则不能偷最后一间。所以可以分两种情况讨论：

- 如果偷了第一间，则不能偷最后一间。使用***数组dp1***记录从第一间开始偷（一定偷第一间）所能获得最大收益。
  - 如果房间是第一间，则***dp1[0] = nums[0]***。
  - 如果房间是第二间，则不能偷，***dp1[1] = nums[1]***。
  - 如果房间是最后一间，则***dp1[nums.size() - 1] = dp1[nums.size() - 2]***。
  - 其他，则***dp1[i] = max(dp[i - 2] + nums[i], dp1[i - 1])***。

- 如果不偷第二间，则第二间可偷可不偷，使用***数组dp2***记录从第二间开始偷（不一定偷，根据动态规划结果决定，但第一间不偷，可以确定***dp2[0] = 0***）所能获得最大收益。
  - 如果房间是第一间，则***dp1[0] = nums[0]***。
  - 如果房间是第二间，则可偷可不偷，***dp1[1] = nums[1]***。
  - 其他，则***dp1[nums.size() - 1] = dp1[nums.size() - 2]***。

  动态规划的时间复杂度为***O(n)***。

  ```c++
  class Solution {
  public:
      int rob(vector<int> &nums) {
          int len = nums.size();
          if (len == 0) {
              return 0;
          } else if  (len == 1) {
              return nums[0];
          }
  
          // 至少有两间房间
  
          // 偷第一间，不能偷最后一间
          vector<int> dp1(len);
          dp1[0] = dp1[1] = nums[0];
  
          // 不偷第一间
          vector<int> dp2(len);
          dp2[0] = 0;
          dp2[1] = nums[1];
  
          for (int i = 2; i < len; ++i) {
              if (i == len - 1) { // 不偷最后一间
                  dp1[i] = dp1[i - 1];
              } else {
                  dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
              }
              dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
          }
  
          return max(dp1[len - 1], dp2[len - 1]);
      }
  };
  ```

  