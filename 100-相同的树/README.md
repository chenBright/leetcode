# 100-相同的树

## 题目

leetcode：[100-相同的树](https://leetcode-cn.com/problems/same-tree/)


## 思路

这是一个递归的过程：判断根结点是否相同，如果不相同，则返回`false`；如果相同，则递归判断左子树和右子树是否都相同。

```c++
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        } else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};
```

