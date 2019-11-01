#include <unordered_map>
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
        unordered_map<TreeNode*, int> m;

        return rob(root, m);
    }
private:
    int rob(TreeNode* root, unordered_map<TreeNode*, int>& m) {
        if (root == NULL) {
            return 0;
        }

        if (m.count(root)) {
            return m[root];
        }

        // 偷取当前结点
        int result1 = root->val;
        if (root->left != NULL) {
            result1 += rob(root->left->left, m) + rob(root->left->right, m);
        }
        if (root->right != NULL) {
            result1 += rob(root->right->left, m) + rob(root->right->right, m);
        }

        // 不偷取当前结点
        int result2 = rob(root->left, m) + rob(root->right, m);

        m[root] = max(result1, result2);

        return m[root];
    }
};
