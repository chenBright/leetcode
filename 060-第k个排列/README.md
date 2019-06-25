# 060-第k个排列

## 题目

leetcode：[060-第k个排列](https://leetcode-cn.com/problems/permutation-sequence/)


## 回溯法

使用回溯法，可以通过单个测试用例。但是提交后，使用所有测试用例的时候，会超时。

## STL next_permutation函数

```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        for (int i = 1; i <= n; ++i) {
            result.push_back(i + '0');
        }

        int j = 0;
        do {
            ++j;
            if (j == k) {
                break;
            }
        } while (next_permutation(result.begin(), result.end()));

        return result;
    }
};
```

## 找规律

参考：

- [博客](https://www.cnblogs.com/grandyang/p/4358678.html)
- [LeetCode评论区 SEU.FidGet 的思路](https://leetcode-cn.com/problems/permutation-sequence/comments/99316)
- [LeetCode powcai 的题解](https://leetcode-cn.com/problems/permutation-sequence/solution/zhao-gui-lu-by-powcai)

```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        string nums = "123456789";
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        --k;
        string result;
        for (int j = n; j >= 1; --j) {
            int tmp = k / factorial[j - 1];
            k %= factorial[j - 1];
            result.push_back(nums[tmp]);
            nums.erase(tmp, 1);
        }

        return result;
    }
};
```

