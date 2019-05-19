# 437-路径总和 III

## 题目

leetcode：[437-路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/)

## 思路

首先先序递归遍历每个节点，再以每个节点作为起始点递归寻找满足条件的路径。

```c++
class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return 0;
        }

        return pathSumRecursion(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:

    int pathSumRecursion(TreeNode *root, int sum) {
        if (root == NULL) {
            return 0;
        }

        int count = 0;
        sum -= root->val;
        if (sum == 0) {
            count = 1;
        }

        return count + pathSumRecursion(root->left, sum) + pathSumRecursion(root->right, sum);
    }
};

```

