# 124-二叉树中的最大路径和

## 题目

leetcode：[124-二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

## 递归

最大路径和：根据当前结点的角色，路径和可分为两种情况：

1. 以当前结点为根结点：
   1. 只有当前结点；
   2. 当前结点+左子树；
   3. 当前结点+右子书；
   4. 当前结点+左右子树。
   
   这四种情况的最大值即为以当前结点为根的最大路径和。此最大值要和已经保存的最大值比较，得到整个树的最大路径值。

2. 当前结点作为父结点路径的一个子结点，需取“单边的最大值”：
   
   1. 只有当前结点；
   2. 当前结点+左子树；
   3. 当前结点+右子数；
   
   这三种情况的最大值。

```c++
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        countNodes(root, maxPath);

        return maxPath;
    }

private:
    int countNodes(TreeNode* root, int& maxPath) {
        if (root == NULL) {
            return 0;
        }
        
        // 如果子树路径和为负，则应当置 0 ，表示最大路径不包含子树。
        int left = max(countNodes(root->left, maxPath), 0);
        int right = max(countNodes(root->right, maxPath), 0);

        // 判断在该节点包含左右子树的路径和，是否大于当前最大路径和。
        maxPath = max(maxPath, root->val + left + right);

        // 返回单边的最大值
        return root->val + max(left, right);
    }
};
```

