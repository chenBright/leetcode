# 235-二叉搜索树的最近公共祖先

## 题目

leetcode：[235-二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

## 迭代

同时在二叉搜索树中搜索结点`p`和结点`q`：

- 当两个结点的值都小于当前结点的值时，则继续递归搜索当前结点的左子树；

- 当两个结点的值都大于当前结点的值时，则继续递归搜索当前结点的右子树；
- 当一个结点的值都大于当前结点的值，一个结点的值都小于当前结点的值时，则当前结点是两个结点的最近公共祖先，返回当前结点。
- 当前结点等于结点`p`，则表示结点`p`是结点`q`的父结点，也是两个结点的最近公共祖先，返回结点`p`；
- 当前结点等于结点`q`，则表示结点`q`是结点`p`的父结点，也是两个结点的最近公共祖先，返回结点`q`；

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *node = root;
        while (node != NULL) {
            if (node == p) {
                return p;
            } else if (node == q) {
                return q;
            } else if (p->val < node->val && q->val < node->val) {
                node = node->left;
            } else if (p->val > node->val && q->val > node->val) {
                node = node->right;
            } else { // 分叉了，则该结点是两个结点的公共结点
                return node;
            }
        }

        return NULL;
    }
};
```

其实，后面三点可以总结为“其他情况”即可。下面是更简洁的实现：

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *node = root;
        while (node != NULL) {
             if (p->val < node->val && q->val < node->val) {
                node = node->left;
            } else if (p->val > node->val && q->val > node->val) {
                node = node->right;
            } else { // 分叉了或者有结点等于当前结点，则该结点是两个结点的公共结点
                return node;
            }
        }

        return NULL;
    }
};
```



## 递归

递归思路同上。

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        if (root == p) {
            return p;
        } else if (root == q) {
            return q;
        } else if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else { // 分叉了，则该结点是两个结点的公共结点
            return root;
        }
    }
};
```

更简洁的实现：

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else { // 分叉了或者有结点等于当前结点，则该结点是两个结点的公共结点
            return root;
        }
    }
};
```

