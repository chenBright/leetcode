# 543-二叉树的直径

## 题目

leetcode：[543-二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)

## 递归

递归计算所有子树的最大路径的结点数，找出最大值，减一即为最大半径。

```c++
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 1;
        maxHeight(root, result);

        // 边数 = 结点数 - 1
        return result - 1;
    }

private:
    int maxHeight(TreeNode* root, int& result) {
        if (root == NULL) {
            return 0;
        }
        // 左子树高度
        int left = maxHeight(root->left, result);
        // 右子树高度
        int right = maxHeight(root->right, result);

        result = max(result, left + right + 1);

        return max(left, right) + 1;
    }
};
```

