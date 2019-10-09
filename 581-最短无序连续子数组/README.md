# 581-最短无序连续子数组

## 题目

leetcode：[581-最短无序连续子数组](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/)

## 选择排序

参考[LeetCode官方题解方法2](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leetcode/)。

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int length = nums.size();
        int left = length;
        int right = 0;
        for (int i = 0; i < length - 1; ++i) {
            for (int j = i + 1; j < length; ++j) {
                if (nums[j] < nums[i]) {
                    left = min(left, i);
                    right = max(right, j);
                }
            }
        }

        return right >= left ? right - left + 1 : 0;
    }
};
```

## 排序

参考[LeetCode官方题解方法3](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leetcode/)。

先排序，在遍历数组，找出左右边界。左边界是第一个与排序后位置不一致的元素的位置，右边界是最后一个与排序后位置不一致的元素的位置。

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int length = nums.size();
        int left = length;
        int right = 0;
        vector<int> snums(nums);
        sort(snums.begin(), snums.end());
        for (int i = 0; i < length; ++i) {
            if (nums[i] != snums[i]) {
                left = min(left, i);
                right = max(right, i);
            }
        }

        return right >= left ? right - left + 1 : 0;
    }
};
```

## 栈

参考[LeetCode官方题解方法4](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leetcode/)。

思想跟选择排序一样。

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int length = nums.size();
        int left = length;
        int right = 0;
        
        stack<int> leftStack;
        for (int i = 0; i < length; ++i) {
            while (!leftStack.empty() &&  nums[leftStack.top()]> nums[i]) {
                left = min(left, leftStack.top());
                leftStack.pop();
            }
            leftStack.push(i);
        }

        stack<int> rightStack;
        for (int j = length - 1; j >= 0; --j) {
            while (!rightStack.empty() && nums[rightStack.top()] < nums[j]) {
                right = max(right, rightStack.top());
                rightStack.pop();
            }
            rightStack.push(j);
        }

        return right >= left ? right - left + 1 : 0;
    }
};
```

## 不使用额外的空间

参考[LeetCode官方题解方法5](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leetcode/)。

存在无序连续子数组时，左边界是第一个大于数组最小值的元素的位置，右边界是最后一个小于数组最大值的元素的位置。

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int length = nums.size();
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        
        // 找最小值
        for (int i = 1; i < length; ++i) {
            if (nums[i] < nums[i - 1]) {
                minNum = min(minNum, nums[i]);
            }
        }
        
        // 找最大值
        for (int i = length - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                maxNum = max(maxNum, nums[i]);
            }
        }

        int left;
        // 从左往右找第一个大于最小值的值的位置
        for (left = 0; left < length; ++left) {
            if (nums[left] > minNum) {
                break;
            }
        }

        int right;
        // 从右往左找第一个小于最大值的值的位置
        for (right = length - 1; right >= 0; --right) {
            if (nums[right] < maxNum) {
                break;
            }
        }

        return right >= left ? right - left + 1 : 0;
    }
};
```

