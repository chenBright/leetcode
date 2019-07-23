#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *node = root;
        while (node != NULL) {
             if (p->val < node->val && q->val < node->val) {
                node = node->left;
            } else if (p->val > node->val && q->val > node->val) {
                node = node->right;
            } else { // 分叉了或者有结点等于当前结点，则该结点是两个结点的公共结点
                return node;
            }
        }

        return NULL;
    }
};