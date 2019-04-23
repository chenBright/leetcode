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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorderTraversal(root, res);
        return res;
    }

private:
    void inorderTraversal(TreeNode *root, vector<int> &res) {
        if (root == NULL) {
            return;
        }

        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right, res);
    }
};