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
    int rob(TreeNode* root) {
        int l = 0;
        int r = 0;

        return helper(root, l, r);
    }
private:
    int helper(TreeNode* root, int&l, int& r) {
        if (root == NULL) {
            return 0;
        }

        int ll = 0;
        int lr = 0;
        int rl = 0;
        int rr = 0;
        l = helper(root->left, ll, lr);
        r = helper(root->right, rl, rr);

        // 偷取当前结点 或者 不偷取当前结点
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};
