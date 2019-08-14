# 287-寻找重复数

## 题目

leetcode：[287-寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/)

## 二分查找

参考[博客解法一](https://github.com/grandyang/leetcode/issues/287)和[LeetCode题解](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419)。

时间复杂度：***O(nlogn)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        // 在[1 ... n]中搜索重复的数字
        int low = 1;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;
            for (const auto &num : nums) {
                if (num <= mid) {
                    ++count;
                }
            }

            if (count > mid) { // 重复数字在前面部分，包括 mid（也有可能是 mid）
                high = mid;
            } else { // 重复数字在后面部分
                low = mid + 1;
            }
        }

        return high;
    }
};
```

## 快慢指针

参考[LeetCode 李一一 的评论](https://leetcode-cn.com/problems/find-the-duplicate-number/comments/33529)和[LeetCode官方题解方法三](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode)。

时间复杂度：***O(nlogn)***。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        for (int i = 0; i != slow; i = nums[i]) {
            slow = nums[slow];
        }

        return slow;
    }
};
```

