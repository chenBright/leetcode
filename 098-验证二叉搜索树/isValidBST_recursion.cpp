#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        lastValue = LONG_MIN;
        return isValidBSTRecursion(root);
    }

private:
    long lastValue; // 上一结点值。类型为 long，是为了避免 node->val = INT_MIN 出错的情况
    bool isValidBSTRecursion(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        bool leftResult = isValidBSTRecursion(root->left);

        // 左子树不是二叉搜索树 或者 左结点值大于等于根结点值
        if (!leftResult || lastValue >= root->val) {
            return false;
        }
        lastValue = root->val;

        bool rightResult = isValidBSTRecursion(root->right);

        return rightResult;
    }
};
