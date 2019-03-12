#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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