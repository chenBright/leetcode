# 114-二叉树展开为链表

## 题目

leetcode：[114-二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)

## 后序遍历（递归）

二叉树展开为链表：

1. 将左子树展开为链表，递归执行；
2. 将右子树展开为链表，递归执行；
3. 如果左子树不为空，将右子树断开，将左子树放到原右子树位置上，将右子树接到“左子树链表”末尾；

```c++
class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        if (left != NULL) {
            flatten(left); // 将左子树展开为链表
        }
        if (right != NULL) {
            flatten(right); // 将右子树展开为链表
        }

        // 如果左子树不为空，将右子树断开，将左子树放到原右子树位置上，将右子树接到“左子树链表”末尾
        if (left != NULL) {
            root->left = NULL;
            root->right = left;
            
            while (left->right != NULL) {
                left = left->right;
            }
            left->right = right;
        }
    }
};
```

## 先序遍历（非递归）

从根节点开始遍历，先检测其左子结点是否存在。如果左子树不为空，将右子树断开，将左子树放到原右子树位置上，将右子树接到左子树最右结点。

```c++
class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        TreeNode *node = root;
        while (node != NULL) {
            TreeNode *ptr = node->left;
            // 如果左子树不为空，将右子树断开，将左子树放到原右子树位置上，将右子树接到左子树最右结点
            if (ptr != NULL) {
                while (ptr->right != NULL) {
                    ptr = ptr->right;
                }
                ptr->right = node->right;
                node->right = node->left;
                node->left = NULL;                
            }
            node = node->right;
        }
    }
};
```

