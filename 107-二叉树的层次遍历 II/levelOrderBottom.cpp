#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;              // 暂存层结果
        TreeNode* lastNode = root;      // 当前层的最后一个结点（最右边的结点）
        TreeNode* nextLastNode = NULL;  // 下一层的最后一个结点（最右边的结点）
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left != NULL) {
                q.push(node->left);
                nextLastNode = node->left;
            }
            if (node->right != NULL) {
                q.push(node->right);
                nextLastNode = node->right;
            }

            // 遍历到层的最后一个结点
            if (node == lastNode) {
                result.push_back(level);
                level.clear();
                lastNode = nextLastNode;
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
