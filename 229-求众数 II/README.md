# 229-求众数 II

## 题目

leetcode：[229-求众数 II](https://leetcode-cn.com/problems/majority-element-ii/)

## 摩尔投票法

参考[LeetCode 李一一 的评论](https://leetcode-cn.com/problems/majority-element-ii/comments/32627)、[LeetCode 灵雨 的题解](https://leetcode-cn.com/problems/majority-element-ii/solution/duo-shu-tou-piao-de-sheng-ji-ban-hao-li-jie-java-b)和[博客](https://www.cnblogs.com/grandyang/p/4606822.html)。

```c++
  vector<int> majorityElement(vector<int> &nums) {
        vector<int> result;
        if (nums.empty()) {
            return result;
        }

        // 定义两个候选人及其对应的票数
        int vote1 = nums[0];
        int count1 = 0;

        int vote2= nums[0]; 
        int count2 = 0;
        for (const int &num : nums) {
            if (num == vote1) {
                ++count1; // 投 vote1
            } else if (num == vote2) {
                ++count2; // 投 vote2
            } else if (count1 == 0) {
                vote1 = num; // vote1 被淘汰，换成 num
                count1 = 1;
                continue;
            } else if (count2 == 0) {
                vote2 = num; // vote2 被淘汰，换成 num
                count2 = 1;
                continue;
            } else {  // 两个候选人都没被淘汰，但票数减一
                --count1;
                --count2;
            }
        }

        // 检查两个数字的出现次数是否真的超过 ⌊ n/3 ⌋ 
        count1 = 0;
        count2 = 0;
        for (const int &num : nums) {
            if (num == vote1) {
                ++count1;
            } else if (num == vote2) {
                ++count2;
            }
        }

        if (count1 > nums.size() / 3) {
            result.push_back(vote1);
        }
        if (count2 > nums.size() / 3 && vote1 != vote2) { // 超过 ⌊ n/3 ⌋ 且两个数字不相等
            result.push_back(vote2);
        }

        return result;
    }
};
```

