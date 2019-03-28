# 303-区域和检索 - 数组不可变

## 题目

leetcode：[303-区域和检索 - 数组不可变](https://leetcode-cn.com/problems/range-sum-query-immutable/)

## 二维数组

假设输入数组的长度为***length***，我们使用***length \* length***的二维数组记录***i……j***的和。每次求和的时候先查找二维数组：

- 如果二维数组已经保存了这一范围的和，则直接返回；
- 如果没有，则计算***sumRange(i, j) = sumRange(i, j - 1) + sums\[j\]\[j\]***。其中***sums\[j\]\[j\] = nums\[j\]***。

最坏情况下，调用sumRange函数的时间复杂度为***O(n)***。该方法很耗内存，空间复杂度为***O(n^2)***。

```c++
class NumArray {
public:
    NumArray(vector<int> nums) : length(nums.size()), sums(length, vector<int>(length, INT_MIN)) {
        int sum = 0;
        for (int i = 0; i < length; ++i) {
            sums[i][i] = nums[i];
            sum += nums[i];
            sums[0][i] = sum; // 计算 0……i 的和
        }
    }
    
    int sumRange(int i, int j) {
        if (i >= length || j >= length || i > j) {
            return INT_MIN;
        }

        // 如果已保存 i……j 的和，则直接返回
        if (sums[i][j] != INT_MIN) {
            return sums[i][j];
        }

        int sum =  sumRange(i, j - 1) + sums[j][j];
        sums[i][j] = sum; // 保存

        return sum;
    }

private:
    int length;
    vector<vector<int> > sums; // 保存 i……j 的和
};
```

## 一维数组

假设输入数组的长度为***length***，我们使用长度为***length***的一维数组sums记录***0……j***的和，则***i……j***范围的和等于

- 如果i等于0，则等于***sums\[j\]***。

- 如果i大于0，则等于***sums[j] - sums[i]***。

调用sumRange函数的时间复杂度为***O(1)***，空间复杂度为***O(n)***。无论是从时间还是空间的角度来看，该方法比使用二维数组的方法都要好。

```c++
class NumArray {
public:
    NumArray(vector<int> nums) : length(nums.size()), sums(length, INT_MIN) {
        if (length == 0) {
            return;
        }

        sums[0] = nums[0];
        for (int i = 1; i < length; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i >= length || j >= length || i > j) {
            return INT_MIN;
        }

        if (i == 0) {
            return sums[j];
        } else {
            return sums[j] - sums[i - 1];
        }
    }

private:
    int length;
    vector<int> sums; // 保存 i……j 的和
};
```

