#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 先序遍历 非递归
class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        TreeNode *node = root;
        while (node != NULL) {
            TreeNode *ptr = node->left;
            // 如果左子树不为空，将右子树断开，将左子树放到原右子树位置上，将右子树接到左子树最右结点
            if (ptr != NULL) {
                while (ptr->right != NULL) {
                    ptr = ptr->right;
                }
                ptr->right = node->right;
                node->right = node->left;
                node->left = NULL;                
            }
            node = node->right;
        }
    }
};