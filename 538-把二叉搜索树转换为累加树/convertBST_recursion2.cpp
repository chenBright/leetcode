#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        convertBST(root->right);
        root->val += sum;
        sum = root->val;
        convertBST(root->left);

        return root;
    }
private:
    int sum = 0;
};