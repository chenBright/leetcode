# 374-猜数字大小

## 题目

leetcode：[374-猜数字大小](https://leetcode-cn.com/problems/guess-number-higher-or-lower/)

## 二分查找

```c++
class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int result = guess(mid);
            if (result == 0) {
                return mid;
            } else if (result == -1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
};
```

## 三分查找

参考[LeetCode官方题解](https://leetcode-cn.com/problems/guess-number-higher-or-lower/solution/cai-shu-zi-da-xiao-by-leetcode/)。

```c++
class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;
            int result1 = guess(mid1);
            int result2 = guess(mid2);
            if (result1 == 0) {
                return mid1;
            } else if (result2 == 0) {
                return mid2;
            } else if (result1 == -1) {
                high = mid1 - 1;
            } else if (result2 == 1) {
                low = mid2 + 1;
            } else {
                low = mid1 + 1;
                high = mid2 - 1;
            }
        }

        return -1;
    }
};
```

## 二分查找和三分查找的比较

参考[LeetCode官方题解](https://leetcode-cn.com/problems/guess-number-higher-or-lower/solution/cai-shu-zi-da-xiao-by-leetcode/)。在最坏情况下三分查找比较次数比二分查找最坏情况要多。