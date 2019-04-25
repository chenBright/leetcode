# 145-二叉树的后序遍历

## 题目

leetcode：[145-二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)

## 递归

```c++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversal(root, res);
        return res;
    }

private:
    void postorderTraversal(TreeNode *root, vector<int> &res) {
        if (root == NULL) {
            return;
        }

        postorderTraversal(root->left, res);
        postorderTraversal(root->right, res);
        res.push_back(root->val);
    }
};
```

## 迭代

```c++
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        stack<TreeNode*> nodeStack;
        TreeNode *node = root;
        TreeNode *lastNode = NULL;
        while (node != NULL || !nodeStack.empty()) {
            if (node != NULL) { // 一直走到最左边
                nodeStack.push(node);
                node = node->left;
            } else { // 处理右子树
                node = nodeStack.top();
                if (node->right != NULL && node->right != lastNode) { // 右子树不为空且没有处理                
                    node = node->right;
                } else {
                    res.push_back(node->val);
                    lastNode = node;
                    /**
                     * 将node设为 NULL，表示子树已处理完，在下一循环处理栈中的结点（即该子树的父结点）
                     * 否则，又重新回到“一直走到最左边”的步骤，导致死循环
                     */
                    node = NULL;
                    nodeStack.pop();
                }
            }
        }

        return res;
    }
};
```

