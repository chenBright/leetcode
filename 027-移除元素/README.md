# 027-移除元素

## 题目

leetcode：[027-移除元素](https://leetcode-cn.com/problems/remove-element/)


## 快慢指针
使用慢指针指向新数组的最后一个元素的后一个元素，快指针遍历元素。遍历的过程中，如果快指针指向的值不等于`val`，则将快指针指向的元素拷贝到慢指针的位置，慢指针也向后移动一个位置。

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int newLen = 0; // 新数组长度
        int pIndex = 0; //遍历指针
        while (pIndex < nums.size()) {
            if (nums[pIndex] != val) {
                nums[newLen++] = nums[pIndex];
            }
            ++pIndex;
        }

        return newLen;
    }
};
```
