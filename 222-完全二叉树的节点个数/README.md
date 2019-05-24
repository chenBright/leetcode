# 222-完全二叉树的节点个数

## 题目

leetcode：[222-完全二叉树的节点个数](https://leetcode-cn.com/problems/count-complete-tree-nodes/comments/)

## 思路

完全二叉树的高度可以直接通过不断地访问左子树计算得到。

判断左右子树的高度: 

- 如果相等，说明左子树是满二叉树, 然后进一步判断右子树的节点数(最后一层最后出现的节点必然在右子树中)。
- 如果不等，说明右子树是深度小于左子树的满二叉树, 然后进一步判断左子树的节点数(最后一层最后出现的节点必然在左子树中) 。

```c++
class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (leftHeight == rightHeight) {
            // 1个根结点 + 左子树（完全二叉树）的结点 + 右子树结点
            return 1 + (pow(2, leftHeight) - 1) + countNodes(root->right);
        } else {
            // 1个根结点 + 右子树（完全二叉树）的结点 + 左子树结点
            return 1 + (pow(2, rightHeight) - 1) + countNodes(root->left);
        }
    }

private:
    int getHeight(TreeNode *root) {
        int height = 0;
        while (root != NULL) {
            ++height;
            root = root->left;
        }

        return height;
    }
};
```

