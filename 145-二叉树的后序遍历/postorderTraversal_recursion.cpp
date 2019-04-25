#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversal(root, res);
        return res;
    }

private:
    void postorderTraversal(TreeNode *root, vector<int> &res) {
        if (root == NULL) {
            return;
        }

        postorderTraversal(root->left, res);
        postorderTraversal(root->right, res);
        res.push_back(root->val);
    }
};
