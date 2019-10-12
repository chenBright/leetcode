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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> s;
        int sum = 0;
        TreeNode* node = root;
        while (!s.empty() || node != NULL) {
            if (node != NULL) {
                s.push(node);
                node = node->right;
            } else {
                node = s.top();
                s.pop();

                node->val += sum;
                sum = node->val;

                node = node->left;
            }
        }

        return root;
    }
};