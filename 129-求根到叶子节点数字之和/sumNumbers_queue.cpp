#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 层序遍历
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root == NULL) {
            return sum;
        }

        queue<TreeNode*> nodeQueue;
        queue<int> valueQueue;
        nodeQueue.push(root);
        valueQueue.push(root->val);
        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            int value = valueQueue.front();
            valueQueue.pop();

            if (node->left == NULL && node->right == NULL) {
                sum += value;
            }

            if (node->left != NULL) {
                nodeQueue.push(node->left);
                valueQueue.push(value * 10 + node->left->val);
            }

            if (node->right != NULL) {
                nodeQueue.push(node->right);
                valueQueue.push(value * 10 + node->right->val);
            }
        }

        return sum;
    }
};