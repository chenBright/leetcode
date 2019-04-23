# 094-二叉树的中序遍历

## 题目

leetcode：[094-二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

## 递归

```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorderTraversal(root, res);
        return res;
    }

private:
    void inorderTraversal(TreeNode *root, vector<int> &res) {
        if (root == NULL) {
            return;
        }

        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right, res);
    }
};
```

## 迭代

```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;

        stack<TreeNode*> nodeStack;
        TreeNode *node = root;
        while (node != NULL || !nodeStack.empty()) {
            if (node != NULL) {
                nodeStack.push(node);
                node = node->left;
            } else {
                node = nodeStack.top();
                nodeStack.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};
```

