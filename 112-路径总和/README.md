# 112-路径总和

## 题目

leetcode：[112-路径总和](https://leetcode-cn.com/problems/path-sum/)

## 代码

```c++
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }

        if (root->left == NULL && root->right == NULL) {
            return sum - root->val == 0;
        }

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
```

