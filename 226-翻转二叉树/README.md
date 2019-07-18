# 226-翻转二叉树

## 题目

leetcode：[226-翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)

## 递归

有两种思路：

1. 先交换左右子树，再递归翻转左右子树；
2. 先递归翻转左右子树，再交换左右子树。

### 实现1

这实现使用的是思路1。

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode *root) {
        invertTreeRecursion(root);
        return root;
    }

private:
    void invertTreeRecursion(TreeNode *root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }

        swap(root->left, root->right);

        invertTreeRecursion(root->left);
        invertTreeRecursion(root->right);
    }
};
```

### 实现2

这实现使用的是思路2。

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode *root) {
        invertTreeRecursion(root);
        return root;
    }

private:
    void invertTreeRecursion(TreeNode *root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }

        invertTreeRecursion(root->left);
        invertTreeRecursion(root->right);

        swap(root->left, root->right);

    }
};
```

### 实现3

这实现使用的是思路2。

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode *root) {
        if (root != NULL) {
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);

            swap(root->left, root->right);

        }

        return root;
    }
};
```

### 实现4

这实现使用的是思路1。

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode *root) {
        if (root != NULL) {
            swap(root->left, root->right);

            root->left = invertTree(root->left);
            root->right = invertTree(root->right);
        }

        return root;
    }
};
```

## 迭代

跟二叉树的层序遍历一样，需要用queue来辅助实现。先把根结点入队，然后从队中取出来，交换其左右子结点。将不为`NULL`的子结点入队，以此类推直到队列中没有结点了，则停止循环，返回`root`即可。

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode *root) {
        if (root == NULL) {
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            swap(node->left, node->right);

            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        return root;
    }
};
```

