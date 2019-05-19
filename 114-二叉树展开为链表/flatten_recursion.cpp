#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 后序遍历 递归
class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        if (left != NULL) {
            flatten(left); // 将左子树展开为链表
        }
        if (right != NULL) {
            flatten(right); // 将右子树展开为链表
        }

        // 如果左子树不为空，将右子树断开，将左子树放到原右子树位置上，将右子树接到“左子树链表”末尾
        if (left != NULL) {
            root->left = NULL;
            root->right = left;
            
            while (left->right != NULL) {
                left = left->right;
            }
            left->right = right;
        }
    }
};