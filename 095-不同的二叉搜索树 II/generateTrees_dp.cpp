#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*> > dp(n + 1);
        if (n == 0) {
            return dp[n];
        }
        dp[0].push_back(NULL);


        // 长度为 1 到 n
        for (int len = 1; len <= n; ++len) {
            for (int root = 1; root <= len; ++root) {
                int left = root - 1; // 左子树结点数
                int right = len - root; // 右子树结点数
                for (auto leftTree : dp[left]) {
                    for (auto rightTree : dp[right]) {
                        TreeNode* rootNode = new TreeNode(root);
                        rootNode->left = leftTree;
                        // 克隆右子树并且加上偏移
                        rootNode->right = clone(rightTree, root);
                        dp[len].push_back(rootNode);
                    }
                }
            }
        }

        return dp[n];
    }

private:
    // 克隆树，并更新结点的值为原值加上偏移
    TreeNode* clone(TreeNode* root, int offset) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* newRoot  = new TreeNode(root->val + offset);
        newRoot->left = clone(root->left, offset);
        newRoot->right = clone(root->right, offset);

        return newRoot;
    }
};
