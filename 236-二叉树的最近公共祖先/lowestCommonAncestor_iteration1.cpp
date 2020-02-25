#include <deque>
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
        deque<TreeNode*> pNodes;
        if (!postOrderIteration(root, p, pNodes)) {
            return NULL;
        }

        deque<TreeNode*> qNodes;
        if (!postOrderIteration(root, q, qNodes)) {
            return NULL;
        }

        TreeNode *ancestor = NULL;
        // 栈顶到栈底为根结点到目标结点。
        // 查找最后一个相等的结点，即为最近公共祖先。
        while (!pNodes.empty() && !qNodes.empty()) {
            if (pNodes.front() != qNodes.front()) {
                break;
            }
            ancestor = pNodes.front();
            pNodes.pop_front();
            qNodes.pop_front();
        }

        return ancestor;
    }

private:
    // 后序遍历查找目标结点
    bool postOrderIteration(TreeNode* root, TreeNode* target, deque<TreeNode*>& nodes) {
        if (root == NULL) {
            return false;
        }

        TreeNode *node = root;
        TreeNode *lastNode = NULL;
        while (!nodes.empty() || node != NULL) {
           if (node != NULL) { // 一直走到最左边
                nodes.push_back(node);
                if (node == target) {
                    return true;
                }
                node = node->left;
            } else {
                node = nodes.back();
                if (node->right != NULL && node->right != lastNode) {
                    node = node->right;
                } else {
                    nodes.pop_back();
                    /**
                     * 将node设为 NULL，表示子树已处理完，在下一循环处理栈中的结点（即该子树的父结点）
                     * 否则，又重新回到“一直走到最左边”的步骤，导致死循环
                     */
                    lastNode = node;
                    node = NULL;
                }
            }
        }

        return false;
    }
};
