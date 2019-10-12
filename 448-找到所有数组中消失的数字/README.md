# 448-找到所有数组中消失的数字

## 题目

leetcode：[448-找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)

## 排序

先排序，再遍历数组，使用变量`previous`记录上一个出现的数字`num`，

- 如果`previous == num`，则继续遍历；
- 如果`previous + 1 != num`，则将[previous, num)范围内的数字加入结果中。

时间复杂度：***O(nlogn)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        if (nums.empty()) {
            return result;
        }

        sort(nums.begin(), nums.end());
        int previous = 0;
        for (const auto &num : nums) {
            if (num == previous) {
                continue;
            }

            // 将 [previous + 1, num) 中间缺少的数字加入到结果中
            for (int i = previous + 1; i < num; ++i) {
                result.push_back(i);
            }
            previous = num;
        }

        // 将 [previous + 1, num.size()] 中间缺少的数字加入到结果中
        for (int i = previous + 1; i <= nums.size(); ++i) {
            result.push_back(i);
        }

        return result;
    }
};
```

## unordered_set

使用`unordered_set`记录出现过的数字，然后从1遍历到n，查找`unordered_set`中是否有出现过该数字。如果没有，则将其加入到结果中。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (s.count(i) == 0) {
                result.push_back(i);
            }
        }

        return result;
    }
};
```

## 标记为负数

将所有正数作为数组下标，置对应数组值为负值。那么，仍为正数的位置即为（未出现过）消失的数字。例如：

- 原始数组：[4,3,2,7,8,2,3,1]
- 重置后为：[-4,-3,-2,-7,`8`,`2`,-3,-1]

结论：[8,2] 分别对应的index为[5,6]（消失的数字）。

时间复杂度：***O(n)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};
```

## 交换

修改前一个方法，改为将`nums[i]`放到`nums[i] - 1`的位置上。这样，最后出现过的数字与其位置的关系为`nums[i] == i + 1`，不符合该条件的`i + 1`即为消失的数字。

其中，交换的方法有多种。因为交换的细节不是该题关注的重点，所以该实现直接使用`swap`函数来交换两个数字。交换的多种方法可以参考[461-汉明距离](../461-汉明距离/README.m)。

时间复杂度：***O(n)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            // 将 nums[i] 放到 nums[nums[i] - 1] 的位置上
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};
```

