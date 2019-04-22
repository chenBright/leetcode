# 209-长度最小的子数组

## 题目

leetcode：[209-长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)

## 滑动窗口

使用两个指针，***left***代表滑动窗口左边，***right***代表滑动窗口右边。

- 当窗口内元素和不大于***s***，则***++right***，扩大窗口；
- 当窗口内元素和大于等于***s***，则***—left***，缩小窗口。

该方法的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int length = nums.size();
        if (length == 0 || s <= 0) {
            return 0;
        }

        int minWindow = 0; // 最小窗口宽度
        int left = 0; // 窗口左边
        int right = 0; // 窗口右边
        int sum = nums[0]; // 窗口和
        while (left < length && right < length) {
            if (sum >= s) { // 满足条件
                int width = right - left + 1;
                minWindow = minWindow == 0 ? width : min(minWindow, width); // 设定最小窗口宽度
                // 减小窗口
                sum -= nums[left];
                ++left;
            } else { // 不满足，则扩大窗口
                ++right;
                if (right >= length) {
                    break;
                }
                sum += nums[right];
            }
        }

        return minWindow;
    }
};
```

## 滑动窗口 + 二分搜索

二分搜索的目标是窗口大小：

- 当该窗口大小符合条件，则缩小窗口。
- 当该窗口大小不符合条件，则扩大窗口。

该方法的时间复杂度为***O(nlogn)***。

```c++
class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int length = nums.size();
        if (length == 0 || s <= 0) {
            return 0;
        }
        
        int minWindow = 0; // 最小窗口宽度
        int left = 0;
        int right = length - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2; // 滑动窗口大小
            if (isSub(mid, s, nums)) { // mid 大的滑动窗口符合条件，则缩小继续搜索
                minWindow = mid;
                left = mid + 1;
            } else { // mid 大的滑动窗口不符合条件，则缩小继续搜索
                right = mid - 1;
            }
        }

        return minWindow;
    }

private:
    bool isSub(int size, int target, vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (i >= size) { // 限制窗口最大为 size
                sum -= nums[i - size];
            }
            if (sum >= target) {
                return true;
            }
        }

        return false;
    }
};
```

