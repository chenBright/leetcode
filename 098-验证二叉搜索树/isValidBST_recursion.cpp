#include <stack>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long lastValue = LONG_MIN; // 上一结点值。类型为 long，是为了避免 node->val = INT_MIN 出错的情况
        stack<TreeNode*> nodeStack;
        TreeNode *node = root;
        while (!nodeStack.empty() || node != NULL) {
            if (node != NULL) {
                nodeStack.push(node);
                node = node->left;
            } else {
                node = nodeStack.top();
                nodeStack.pop();
                if (node->val > lastValue) {
                    lastValue = node->val;
                } else {
                    return false;
                }
                node = node->right;
            }
        }

        return true;
    }
};
