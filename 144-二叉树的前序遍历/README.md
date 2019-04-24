# 144-二叉树的前序遍历

## 题目

leetcode：[144-二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)

## 递归

```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preorderTraversal(root, res);
        return res;
    }

private:
    void preorderTraversal(TreeNode *root, vector<int> &res) {
        if (root == NULL) {
            return;
        }

        res.push_back(root->val);
        preorderTraversal(root->left, res);
        preorderTraversal(root->right, res);
    }
};
```

## 迭代

```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;

        stack<TreeNode*> nodeStack;
        TreeNode *node = root;
        while (node != NULL || !nodeStack.empty()) {
            if (node != NULL) {
                nodeStack.push(node);
                res.push_back(node->val);
                node = node->left;
            } else {
                node = nodeStack.top();
                nodeStack.pop();
                node = node->right;
            }
        }
        return res;
        
    }
};
```

