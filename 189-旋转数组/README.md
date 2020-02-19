# 189-旋转数组

## 题目

leetcode：[189-旋转数组](https://leetcode-cn.com/problems/rotate-array/)

## 循环移动

借助一个变量，来将数组循环移动k次。但当数组长度和k很大时，很耗时，LeetCode输出“超出时间限制”。

该方法的时间复杂度为**O(kn)**，空间复杂度为**O(1)**。

```c++
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int length = nums.size();
        if (length == 0 || length == 1) {
            return;
        }

        // 当k大于数组长度时，取余
        if (k > length) {
            k = k % length;
        }

        int temp;
        for (int i = 0; i < k; ++i) {
            temp = nums[length - 1]; // 暂存最后一个元素
            for (int j = length - 1; j > 0; --j) {
                nums[j] = nums[j - 1];
            }
            nums[0] = temp; // 移动最后一个元素
        }
    }
};
```

## 翻转

通过三次翻转实现：

1. reverse(1, nums.size() - 1);

2. reverse(0, n);

3. reverse(i, nums.size() - 1);

例如nums为`1, 2, 3, 4, 5, 6`，n为`3`：

1. 1, 2, 3, 4, 5, 6 -=> 6, 5, 4, 3, 2, 1

2. 6, 5, 4, 3, 2, 1 -=> 4, 5, 6, 3, 2, 1

3. `4, 5, 6, 3, 2, 1 -=> 4, 5, 6, 1, 2, 3`

该方法的时间复杂度为**O(n)***，空间复杂度为**O(1)**。

```c++
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int length = nums.size();
        if (length == 0 || length == 1) {
            return;
        }

        if (k > length) {
            k = k % length;
        }

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```

## 交换

使用交换的方法将元素一次性交换到最终位置，先使用`nums[0]`存放将要交换的元素，`base`变量保存该索引，即`base = 0`，`place`变量保存被交换的元素的位置。

- 交换完后，更新place，`place = (place + k) % nums.size()`。
- 如果`base == place`，即被交换过来的元素已经在最终位置上，即该元素的最终位置就是现在用于存放交换元素的位置，则
  1. 向前移动base位置，即***base + 1***（此位置的元素一定未在最终位置上）。
  2. 跳过该元素，且更新place。

该方法的时间复杂度为***O(n)***，空间复杂度为***O(1)***。

```c++
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int length = nums.size();
        if (length == 0 || length == 1) {
            return;
        }

        if (k > length) {
            k = k % length;
        }

        int base = 0;
        int place = (base + k) % length;
        for (int i = 0; i < length; ++i) {
            swap(nums[base], nums[place]);
            place = (place + k) % length;
            // 被交换到base位置上的元素的最终位置就是base，则移动base位置、跳过该元素、更新place
            if (base == place) {
                ++base; // 移动base位置
                ++i; // 跳过该元素
                place = (base + k) % length; // 更新place
            }
        }
    }
};
```

