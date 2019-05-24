#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (leftHeight == rightHeight) {
            // 1个根结点 + 左子树（完全二叉树）的结点 + 右子树结点
            return 1 + (pow(2, leftHeight) - 1) + countNodes(root->right);
        } else {
            // 1个根结点 + 右子树（完全二叉树）的结点 + 左子树结点
            return 1 + (pow(2, rightHeight) - 1) + countNodes(root->left);
        }
    }

private:
    int getHeight(TreeNode *root) {
        int height = 0;
        while (root != NULL) {
            ++height;
            root = root->left;
        }

        return height;
    }
};