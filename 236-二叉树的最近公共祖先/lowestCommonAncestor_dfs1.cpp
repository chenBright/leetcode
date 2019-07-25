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
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        stack<TreeNode*> pNodes;
        dfs(root, p, pNodes);

        stack<TreeNode*> qNodes;
        dfs(root, q, qNodes);

        TreeNode *ancestor = NULL;
        // 栈顶到栈地为根结点到目标结点
        // 查找最后一个相等的结点，即为最近公共祖先
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
    bool dfs(TreeNode *root, TreeNode *target, stack<TreeNode*> &nodes) {
        if (root == NULL) {
            return false;
        }

        if (root == target) {
            nodes.push(target);
            return true;
        }

        bool leftResult = dfs(root->left, target, nodes);
        if (leftResult) {
            nodes.push(root);
            return true;
        }

        bool rightResult = dfs(root->right, target, nodes);

        if (rightResult) {
            nodes.push(root);
            return true;
        }

        return false;
    }
};