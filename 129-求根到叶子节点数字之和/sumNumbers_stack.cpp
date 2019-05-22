#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 先序遍历 非递归实现
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root == NULL) {
            return sum;
        }

        // 每个结点对应着一个和
        stack<TreeNode*> nodeStack; // 结点栈
        stack<int> valueStack; // “和”栈
        nodeStack.push(root);
        valueStack.push(root->val);

        // 先序遍历
        while (!nodeStack.empty()) {
            TreeNode *node = nodeStack.top();
            nodeStack.pop();
            int value = valueStack.top();
            valueStack.pop();

            if (node->left == NULL && node->right == NULL) {
                sum += value;
            }

            if (node->right != NULL) {
                nodeStack.push(node->right);
                valueStack.push(value * 10 + node->right->val);
            }
            if (node->left !=  NULL) {
                nodeStack.push(node->left);
                valueStack.push(value * 10 + node->left->val);
            }
        }

        return sum;
    }
};