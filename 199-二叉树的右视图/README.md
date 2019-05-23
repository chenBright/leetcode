# 199-二叉树的右视图

## 题目

leetcode：[199-二叉树的右视图](https://leetcode-cn.com/problems/binary-tree-right-side-view/)

## 层序遍历

- 使用层序遍历遍历二叉树。

- 使用变量`currentRight`记录当前遍历的层的最右结点，用于确定是否遍历完一层。

- 使用变量`right`记录下一层的最右结点，当***currentRight == currentRight***时，表示已经遍历到当前层的最右结点，此时，`right`保存的结点即为下一层的最右结点。

```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        queue<TreeNode*> nodeQueue; // 结点队列
        nodeQueue.push(root);
        res.push_back(root->val);
        TreeNode *currentRight = root; // 当前上一层最右的结点
        TreeNode *right = NULL; // 下一层最右结点
        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            if (node->left != NULL) {
                right = node->left;
                nodeQueue.push(node->left);
            }
            if (node->right != NULL) {
                right = node->right;
                nodeQueue.push(node->right);
            }
            // 遍历到最右结点，且不是最后一层
            if (node == currentRight && right != NULL) {
                currentRight = right;
                res.push_back(right->val);
                right = NULL; // 恢复为 NULL
            }
        }

        return res;
    }
};
```

