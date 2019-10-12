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
        int sum = 0;
        convert(root, sum);

        return root;
    }

private:
    void convert(TreeNode* root, int& sum) {
        if (root == NULL) {
            return;
        }

        convert(root->right, sum);
        root->val += sum;
        sum = root->val;
        convert(root->left, sum);

    }
};