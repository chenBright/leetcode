# 238-除自身以外数组的乘积

## 题目

leetcode：[238-除自身以外数组的乘积](https://leetcode-cn.com/problems/product-of-array-except-self/)

## 动态规划

细心观察可以知道，`当前位置的乘积 = 当前数字左边的乘积 * 当前数字右边的乘积`。

### 两个数组

使用两个数组分别记录左边和右边的乘积。

记录左边乘积的数组`left`：

- 当 `i = 0`时，`left[i] = 1`；
- 当`i > 0`时，`left[i] = left[i - 1] * nums[1]`。

记录右边乘积的数组`right`：

- 当`i = nums.size() - 1`时，`right[i] = 1`；
- 当`i < nums.size() - 1`时，`right[i] = right[i + 1] * nums[i + 1]`。

时间复杂度为：***O(n)***。

空间复杂度为：***O(n)***。

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = nums.size();
        vector<int> result(len);

        int product = 1;
        vector<int> left(len, 1); // left[i] 表示 nums[i] 左边乘积
        for (int i = 0; i < len; ++i) {
            left[i] = product;
            product *= nums[i];
        }

        product = 1;
        vector<int> right(len, 1); // right[i] 表示 nums[i] 右边乘积
        for (int j = len - 1; j >= 0; --j) {
            right[j] = product;
            product *= nums[j];
        }

        for (int k = 0; k < len; ++k) {
            result[k] = left[k] * right[k];
        }

        return result;
    }
};
```

### 无需额外空间（结果数组除外）

观察上面的方法会发现，每一次循环只需要用到上一次循环的计算结果，所以并不需要使用数组记录所有的计算结果，只需要一个变量来记录上一次循环的计算结果即可。而每一次循环的计算结果直接与`result[i]`相乘，并记录会`result[i]`中。这样就能将空间复杂度降到常数量级。

时间复杂度为：***O(n)***。

空间复杂度为：***O(1)***，结果数组除外。

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int len = nums.size();
        vector<int> result(len);

        int product = 1;
        for (int i = 0; i < len; ++i) {
            result[i] = product;
            product *= nums[i];
        }

        product = 1;
        for (int j = len - 1; j >= 0; --j) {
            result[j] = product;
            product *= nums[j];
        }

        return result;
    }
};
```

