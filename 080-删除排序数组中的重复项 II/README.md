# 080-删除排序数组中的重复项 II

## 题目

leetcode：[080-删除排序数组中的重复项 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/)


## 思路

使用两个指针，一个指针***length***记录新数组的长度，一个指针***i***用于遍历旧数组。

### 实现1

使用一个变量记录***nums\[length - 1\] == nums\[length - 2\]***。

```c++
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        bool isDouble = false; // 标记 nums[length - 1] == nums[length - 2]
        int length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[length - 1]) { // 不重复的元素
                nums[length++] = nums[i];
                isDouble = false;
            } else {
                if (!isDouble) { // nums[length - 1] != nums[length - 2]
                    nums[length++] = nums[i];
                    isDouble = true;
                }
            }
        }

        return length;
    }
};
```

### 实现2

利用有序数组的特性，因为每个元素最多出现两次，所以***nums[i] > nums[i - 2]***肯定成立，其中 i 大于等于2。

```c++
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < 2 || nums[i] > nums[length - 2]) {
                nums[length++] = nums[i];
            }
        }

        return length;
    }
};
```

