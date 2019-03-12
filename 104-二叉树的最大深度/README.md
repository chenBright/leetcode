# 104-二叉树的最大深度

## 题目

leetcode：[104-二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)


## 递归

```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
```

## 层序遍历

使用层序遍历的思想，计算二叉树的深度。

```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int count = 0; // 记录深度
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ++count;

            vector<TreeNode*> v; // 保存子结点
            // 一次性处理一行
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL) {
                    v.push_back(node->left);
                }
                if (node->right != NULL) {
                    v.push_back(node->right);
                }
            }
            for (vector<TreeNode*>::iterator it = v.begin(); it != v.end(); ++it) {
                q.push(*it);
            }
        }

        return count;
    }
};
```

