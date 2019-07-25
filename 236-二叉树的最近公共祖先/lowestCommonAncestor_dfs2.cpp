#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left != NULL && right != NULL) {
            return root;
        }

        // 当 left 不为空，right 为空，则 left 是 right 的父结点
        // 当 right 不为空，left 为空，则 right 是 left 的父结点
        // 否则，p、q 都不是 root 的子孙结点
        return left != NULL ? left : right;
    }
};