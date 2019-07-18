#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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