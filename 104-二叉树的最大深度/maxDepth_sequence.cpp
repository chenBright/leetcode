#include <queue>
#include <vector>
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int count = 0; // 记录深度
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ++count;

            vector<TreeNode*> v; // 保存子结点
            // 一次性处理一行
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL) {
                    v.push_back(node->left);
                }
                if (node->right != NULL) {
                    v.push_back(node->right);
                }
            }
            for (vector<TreeNode*>::iterator it = v.begin(); it != v.end(); ++it) {
                q.push(*it);
            }
        }

        return count;
    }
};