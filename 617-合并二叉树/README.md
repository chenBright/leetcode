# 617-合并二叉树

## 题目

leetcode：[617-合并二叉树](https://leetcode-cn.com/problems/merge-two-binary-trees/)

## 实现

```c++
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        } else if (t1 == NULL && t2 != NULL) {
            return t2;
        } else if (t1 != NULL && t2 == NULL) {
            return t1;
        } else {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);

            return t1;
        }
    }
};
```

