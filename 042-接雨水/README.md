# 042-接雨水

## 题目

leetcode：[042-接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)

## 按行求解

参考[LeetCode题解”按行求“的方法](https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)。

时间复杂度：**O(n^2)**。

空间复杂度：**O(1)**。

```c++
class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        if (height.empty()) {
            return sum;
        }

        auto maxHeightIt = max_element(height.begin(), height.end());
        for (int i = 1; i <= *maxHeightIt; ++i) {
            bool isStart = false; // //标记是否开始更新 tmpSum
            int tmpSum = 0;
            for (int j = 0; j < height.size(); ++j) {
                if (isStart && height[j] < i) {
                    ++tmpSum;
                }
                if (height[j] >= i) {
                    sum += tmpSum;
                    tmpSum = 0;
                    isStart = true;
                }
            }
        }

        return sum;
    }
};
```

## 按列求解

参考[LeetCode题解”按列求“的方法](https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)。

时间复杂度：**O(n^2)**。

空间复杂度：**O(1)**。

```c++
class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        if (height.empty()) {
            return sum;
        }

        for (int i = 1; i < height.size() - 1; ++i) {
            int maxLeft = 0;
            // 找出左边最高
            for (int j = i - 1; j >= 0; --j) {
                maxLeft = max(maxLeft, height[j]);
            }

            int maxRight = 0;
            // 找出右边最高
            for (int k = i + 1; k < height.size(); ++k) {
                maxRight = max(maxRight, height[k]);
            }

            int minHeight = min(maxLeft, maxRight);
            // 只有较小的一段大于当前列的高度才会有水，其他情况不会有水
            if (minHeight > height[i]) {
                sum += minHeight - height[i];
            }
        }

        return sum;
    }
};
```

## 按列求解 + 动态规划

### 两个数组

参考[LeetCode题解”动态规划“的思路](https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)和[LeetCode官方题解”动态编程“的代码](https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode/)。

时间复杂度：**O(n^2)**。

空间复杂度：**O(n)**。

```c++
class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        if (height.empty()) {
            return sum;
        }

        int length = height.size();
        vector<int> maxLefts(length);
        for (int i = 1; i < length; ++i) {
            maxLefts[i] = max(maxLefts[i - 1], height[i - 1]);
        }

        vector<int> maxRights(length);
        for (int j = length - 2; j >= 0; --j) {
            maxRights[j] = max(maxRights[j + 1], height[j + 1]);
        }

        for (int k = 1; k < length - 1; ++k) {
            int minHeight = min(maxLefts[k], maxRights[k]);
            // 只有较小的一段大于当前列的高度才会有水，其他情况不会有水
            if (minHeight > height[k]) {
                sum += minHeight - height[k];
            }
        }

        return sum;
    }
};
```

### 一个数组

参考[LeetCode题解”双指针“的方法](https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)。

其实可以不使用`maxLefts`数组，将计算`maxLeft`放到最后的循环再计算即可。

时间复杂度：***O(n)***。

空间复杂度：***O(n)***。

```c++
class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        if (height.empty()) {
            return sum;
        }

        int length = height.size();
        vector<int> maxRights(length);
        for (int i = length - 2; i >= 0; --i) {
            maxRights[i] = max(maxRights[i + 1], height[i + 1]);
        }

        int maxLeft = 0;
        for (int j = 1; j < length - 1; ++j) {
            maxLeft = max(maxLeft, height[j - 1]);
            int minHeight = min(maxLeft, maxRights[j]);
            // 只有较小的一段大于当前列的高度才会有水，其他情况不会有水
            if (minHeight > height[j]) {
                sum += minHeight - height[j];
            }
        }

        return sum;
    }
};
```

### 不需要数组（双指针）

参考[LeetCode题解”双指针“的方法](https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)。

时间复杂度：**O(n)**。

空间复杂度：**O(1)**。

```c++
class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        int length = height.size();
        int maxLeft = 0;
        int maxRight = 0;
        int left = 1;
        int right = length - 2;
        while (right - left >= 0) {
            // height [ left - 1] 是可能成为 maxLeft 的变量，
            // 同理，height [ right + 1 ] 是可能成为 maxRight 的变量。
            // 只要保证 height [ left - 1 ] < height [ right + 1 ]，
            // 那么 maxLeft 就一定小于 maxRight。
            if (height[left - 1] < height[right + 1]) { // 从左到右更
                maxLeft = max(maxLeft, height[left - 1]);
                if (maxLeft > height[left]) {
                    sum += maxLeft - height[left];
                }
                ++left;
            } else { // 从右到左更
                maxRight = max(maxRight, height[right + 1]);
                if (maxRight > height[right]) {
                    sum += maxRight - height[right];
                }
                --right;
            }
        }

        return sum;
    }
};
```

## 栈

参考[LeetCode题解”双指针“的方法](https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)。

时间复杂度：**O(n)**。

空间复杂度：**O(n)**。

```c++
class Solution {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        int current = 0;
        stack<int> s;

        while (current < height.size()) {
            // 如果栈不空并且当前指向的高度大于栈顶高度就一直循环
            while (!s.empty() && height[current] > height[s.top()]) {
                int h = height[s.top()];
                s.pop();
                if (s.empty()) {
                    break;
                }
                int distance = current - s.top() - 1; // 两堵墙之前的距离
                int minHeight = min(height[s.top()], height[current]);
                sum += distance * (minHeight - h);
            }
            s.push(current);
            ++current;
        }

        return sum;
    }
};
```

