# 110-平衡二叉树

## 题目

leetcode：[110-平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/)

## 思路

判断每个结点的左右子树是不是平衡二叉树，这是一个递归的过程。

```c++
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalanced(root, &depth);
    }

private:
    bool isBalanced(TreeNode *root, int *treeDepth) {
        if (root == NULL) {
            *treeDepth = 0;
            return true;
        }

        int leftTreeDepth = 0;
        int rightTreeDepth = 0;
        if (isBalanced(root->left, &leftTreeDepth) && isBalanced(root->right, &rightTreeDepth)) {
            int diff = abs(leftTreeDepth - rightTreeDepth);
            if (diff <= 1) {
                *treeDepth = max(leftTreeDepth, rightTreeDepth) + 1;
                return true;
            }
        }

        return false;
    }
};
```

