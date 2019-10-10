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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 1;
        maxHeight(root, result);

        // 边数 = 结点数 - 1
        return result - 1;
    }

private:
    int maxHeight(TreeNode* root, int& result) {
        if (root == NULL) {
            return 0;
        }
        // 左子树高度
        int left = maxHeight(root->left, result);
        // 右子树高度
        int right = maxHeight(root->right, result);

        result = max(result, left + right + 1);

        return max(left, right) + 1;
    }
};