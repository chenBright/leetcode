# 035-搜索插入位置

## 题目

leetcode：[035-搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/)


## 暴力破解
遍历数组每个元素，找到第一个大于等于target的元素的位置并返回。如果数组中没有大于等于target的元素，则返回素组长度。

该方法的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] >= target) {
                break;
            }
            ++i;
        }

        return i;
    }
};
```

## 二分查找

二分查找：

- 如果数组中存在等于target的元素，则返回该元素的索引。
- 如果数组中不存在等于target的元素，则返回二分查找结束时`low`指向的位置。

该方法的时间复杂度为**O(logn)**。

## 迭代实现

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
```

### STL lower_bound

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }

        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
```

