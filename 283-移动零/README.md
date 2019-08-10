# 283-移动零

## 题目

leetcode：[283-移动零](https://leetcode-cn.com/problems/move-zeroes/)

## 双指针（交换）

时间复杂度：***O(n)***。

空间复杂度：***O(1)***。

### 实现1

使用两个指针`i`和`j`：

- 找到第一个`0`元素，令`i`指向该元素，再完后找到第一个非`0`元素，令`j`指向该元素，最后交换这两个位置的元素；
- 继续遍历，直到结束。

```c++
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        int j = 0;
        int len = nums.size();
        while (i < len && j < len) {
            // 找 0 元素
            while (i < len && nums[i] != 0) {
                ++i;
            }

            // 找非 0 元素
            j = i + 1;
            while (j < len && nums[j] == 0) {
                ++j;
            }

            // 交换
            if (i < len && j < len) {
                swap(nums[i++], nums[j]);
            }
        }
    }
};
```

### 实现2

[LeetCode官方题解的”最优解“](https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode)的实现也是使用双指针，但实现得比较简洁，且比***实现1***更优。因为***实现1***的`j`指针每次都是从`i + 1`开始，如果`i + 1`是`0`元素，且上一次已经遍历过，则这样就会重复遍历。而该实现的`j`指针没有重复遍历，它会一直遍历到非`0`元素在交换，并不依赖`i`指针。

```c++
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            if (nums[j] != 0) {
                swap(nums[i++], nums[j]);
            }
        }
    }
};
```

### 实现3

***实现2***还是有一部分重复操作：当`i == j`且`nums[j] != 0`，即`i`、`j`指针重合的时候，它们指向的是相同的非`0`元素，没有必要调用`swap`函数（虽然不知道`swap`函数内部有没有真正的交换，但是还是多了一次调用）。

该实现是基于***实现1***的，`j`指针不依赖`i`指针，`j`指针自己向后遍历，找到非`0`元素。

```c++
        int j = 0;
        int len = nums.size();

        while (i < len && nums[i] != 0) {
            ++i;
        }

        j = i + 1;
        while (j < len && nums[j] == 0) {
            ++j;
        }

        while (i < len && j < len) {
            swap(nums[i++], nums[j++]);

            while (i < len && nums[i] != 0) {
                ++i;
            }

            while (j < len && nums[j] == 0) {
                ++j;
            }
        }
    }
};
```

## 双指针（不需要交换）

其实可以不需要交换，只要将非`0`元素移动到数组前面，再在后面补`0`即可。

该实现的最坏情况是：存在大量的`0`元素，例如`[0 0 0 ... 0 1]`。最后需要补`n - 1`个`0`。但是基于交换的实现，只需要交换一次即可，不需要其他操作。

时间复杂度：***O(n)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        int j = 0;
        int len = nums.size();

        while (i < len && j < len) {
            // 将非 0 元素移动到数组前面
            if (nums[j] != 0) {
                nums[i++] = nums[j];
            }
            ++j;
        }

        // 在数组后面补 0
        while (i < len) {
            nums[i] = 0;
        }
    }
};
```

