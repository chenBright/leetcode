#include <limits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        int n = count(root->left);
        if (k <= n) { // 在左子树找到第k小的结点
            return kthSmallest(root->left, k);
        } else if (k > n + 1) { // 在右子树找到第k小的结点
            return kthSmallest(root->right, k - n - 1);
        } else { // 当前结点是第k小的结点
            return root->val;
        }
    }
private:
    // 计算树的结点数
    int count(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }

        return 1 + count(node->left) + count(node->right);
    }
};
