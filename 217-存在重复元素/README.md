# 217-存在重复元素

## 题目

leetcode：[217-存在重复元素](https://leetcode-cn.com/problems/contains-duplicate/)

## 蛮力法

使用两层循环，第一层循环遍历数组，第二层遍历第一层循环遍历到的元素后面的元素，两者比较，如果相等，则返回true；否则，继续遍历。如果遍历完数组，也没有重复的数字，则返回false。

蛮力法的时间复杂度为***O(n^2)***。

代码略。

## 先排序，再找相邻元素相等的元素

该方法的主要工作为排序，则时间复杂度为***O(nlogn)***。

```c++
class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        // nums.size() 返回的数据类型为 unsighed long，
        // 如果数组长度为 0，再 - 1，结果溢出，最后导致进入循环，数组越界访问
        for (int i = 0; i < static_cast<int>(nums.size()) - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
};
```

***注意***：nums.size() 返回的数据类型为`unsighed long`，如果数组长度为 0，再 - 1，结果溢出，最后导致进入循环，数组越界访问。

对数组进行判空，在LeetCode提交，运行速度会快一些。应该是因为少了后面`sort`函数调用的。

```c++
class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        if (nums.empty()) {
            return false;
        }
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
};
```

## Set

使用`Set`保存第一次出现的数字，在遍历数组过程中，如果`Set`中已经有该数字，则返回true。如果遍历完数组，也没有重复的数字，则返回false。

该方法的时间复杂度为***O(n***)，空间复杂度为***O(n)***。

```c++
class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }

        return false;
    }
};
```

简洁的实现：

```c++
class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        return s.size() != nums.size();
    }
};
```

