# 101-对称二叉树

## 题目

leetcode：[101-对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)


## 递归

```c++
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        return isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) {
            return true;
        } else if (left == NULL || right == NULL) { // 其中一个为空结点，另一个为非空结点
            return false;
        }

        if (left->val != right->val) {
            return false;
        } else {
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }
    }
};
```

## 迭代

用栈来保存对应的左右·结点，每次将对应的两个结点进栈，出栈的时候将位于最上面的两个结点出栈进行比较。

```c++
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        stack<TreeNode*> s;
        // 左右子树作为一组进栈
        s.push(root->left);
        s.push(root->right);

        while (!s.empty()) {
            TreeNode *p = s.top();
            s.pop();
            TreeNode *q = s.top();
            s.pop();

            if (p == NULL && q == NULL) {
                continue;
            } else if (p == NULL || q == NULL) { // 其中一个为空结点，另一个为非空结点
                return false;
            }

            if (p->val != q->val) {
                return false;
            } else {
                // 左右子树对应进栈
                s.push(p->left);
                s.push(q->right);

                s.push(p->right);
                s.push(q->left);
            }
        }

        return true;
    }
};
```

