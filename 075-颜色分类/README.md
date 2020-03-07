# 075-颜色分类

## 题目

leetcode：[075-颜色分类](https://leetcode-cn.com/problems/sort-colors/)


## 计数排序

第一次遍历数组，记录0、1、2的个数。第二遍遍历数组，重写数组。

该方法的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    void sortColors(vector<int> &nums) {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        for (const auto &num : nums) {
            if (num == 0) {
                ++count0;
            } else if (num == 1) {
                ++count1;
            } else {
                ++count2;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (i < count0) {
                nums[i] = 0;
            } else if (i < count0 + count1) {
                nums[i] = 1;
            } else {
                nums[i] = 2;
            }
        }
    }
};
```

## 三向切分快速排序的 Paritition

使用[《算法》](<https://book.douban.com/subject/10432347/>)P188 中的“三向切分的快速排序”，从左到右遍历数组，维护一个指针`low`使得`nums[0 … low - 1]`中的元素都小于 1，一个指针`high`使得`nums[high … nums.size() - 1]`中的元素都大于1，一个指针`i`（用于遍历数组）使得`nums[low … i - 1]`中的元素都等于 1，`nums[i … high]`中的元素还未确定大小。

- `nums[i]`小于 1，则交换位置`num[low]`和`nums[i]`，`++low`，`++i`；
- `nums[i]`大于 1，则交换位置`num[high]`和`nums[i]`，`--high`；
- `nums[i]`等于 1，`++i`。

该方法的时间复杂度为**O(n)**。

```c++
class Solution {
public:
    void sortColors(vector<int> &nums) {
        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;
        int i = 0;
        /**
         * [0...low - 1]为小于 1 的数，即0
         * [low...i]为等于 1 的数
         * [i...high]为不确定大小的数
         * [high...nums.size() - 1]为大于 1 的数，即2
         */
        while (i <= high) {
            if (nums[i] < 1) {
                swap(nums[low++], nums[i++]);
            } else if (nums[i] > 1) {
                swap(nums[i], nums[high--]);
            } else {
                ++i;
            }
        }
    }
};
```

