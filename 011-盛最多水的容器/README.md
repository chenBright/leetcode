# 011-盛最多水的容器

## 题目

leetcode：[011-盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)


## 双指针法
参考[LeetCode 盛最多水的容器官方解答](https://leetcode-cn.com/problems/container-with-most-water/solution/)。

双指针法的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    int maxArea(vector<int> &height) {
        int len = height.size();
        if (len < 2) {
            return 0;
        }

        int left = 0;
        int right = len - 1;
        int maxArea = 0;
        while (left < right) {
            int minHeight = min(height[left], height[right]);
            maxArea = max(maxArea, (right - left) * minHeight);
            // 移动高度小的一边
            if (minHeight == height[left]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxArea;
    }
};
```

