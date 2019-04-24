#include <vector>
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;

        stack<TreeNode*> nodeStack;
        TreeNode *node = root;
        while (node != NULL || !nodeStack.empty()) {
            if (node != NULL) {
                nodeStack.push(node);
                res.push_back(node->val);
                node = node->left;
            } else {
                node = nodeStack.top();
                nodeStack.pop();
                node = node->right;
            }
        }
        return res;
        
    }
};