# 026-删除排序数组中的重复项

## 题目

leetcode：[026-删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)


## 快慢指针
使用慢指针指向新数组的最后一个元素，快指针遍历元素。遍历的过程中，如果两个指针指向的值不相等，则将快指针指向的元素拷贝到慢指针后面，慢指针也向后移动一个位置。

```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int frontP = 0; // 指向新数组的最后一个元素
        int endP = 1; // 用于遍历旧数据

        while (endP < nums.size()) {
            if (nums[frontP] != nums[endP]) {
                ++frontP;
                nums[frontP] = nums[endP];
            }
            ++endP;
        }

        return frontP + 1;
    }
};
```

