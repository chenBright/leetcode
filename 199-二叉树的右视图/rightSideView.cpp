#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        queue<TreeNode*> nodeQueue; // 结点队列
        nodeQueue.push(root);
        res.push_back(root->val);
        TreeNode *currentRight = root; // 当前上一层最右的结点
        TreeNode *right = NULL; // 下一层最右结点
        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            if (node->left != NULL) {
                right = node->left;
                nodeQueue.push(node->left);
            }
            if (node->right != NULL) {
                right = node->right;
                nodeQueue.push(node->right);
            }
            // 遍历到最右结点，且不是最后一层
            if (node == currentRight && right != NULL) {
                currentRight = right;
                res.push_back(right->val);
                right = NULL; // 恢复为 NULL
            }
        }

        return res;
    }
};
