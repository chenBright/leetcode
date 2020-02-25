#include <stack>
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
        stack<TreeNode*> pNodes;
        if (!postOrder(root, p, pNodes)) {
            return NULL;
        }

        stack<TreeNode*> qNodes;
        if (!postOrder(root, q, qNodes)) {
            return NULL;
        }

        TreeNode *ancestor = NULL;
        // 栈顶到栈底为根结点到目标结点。
        // 查找最后一个相等的结点，即为最近公共祖先。
        while (!pNodes.empty() && !qNodes.empty()) {
            if (pNodes.top() != qNodes.top()) {
                break;
            }
            ancestor = pNodes.top();
            pNodes.pop();
            qNodes.pop();
        }

        return ancestor;
    }

private:
    // 后序遍历查找目标结点
    bool postOrder(TreeNode* root, TreeNode* target, stack<TreeNode*>& nodes) {
        if (root == NULL) {
            return false;
        }

        if (root == target
            || postOrder(root->left, target, nodes)
            || postOrder(root->right, target, nodes)) {
            nodes.push(root);
            return true;
        }

        return false;
    }
};