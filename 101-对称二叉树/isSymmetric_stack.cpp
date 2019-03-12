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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        stack<TreeNode*> s;
        // 左右子树作为一组进栈
        s.push(root->left);
        s.push(root->right);

        while (!s.empty()) {
            TreeNode *p = s.top();
            s.pop();
            TreeNode *q = s.top();
            s.pop();

            if (p == NULL && q == NULL) {
                continue;
            } else if (p == NULL || q == NULL) { // 其中一个为空结点，另一个为非空结点
                return false;
            }

            if (p->val != q->val) {
                return false;
            } else {
                // 左右子树对应进栈
                s.push(p->left);
                s.push(q->right);

                s.push(p->right);
                s.push(q->left);
            }
        }

        return true;
    }
};