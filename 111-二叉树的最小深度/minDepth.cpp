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
    int minDepth(TreeNode* root) {
        int count = 0;
        if (root == NULL) {
            return count;
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> v; // 保存子结点
        bool isFindMin = false;
        while (!q.empty()) {
            ++count;
            // 一次性处理一行
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();

                // 找到叶子结点
                if (node->left == NULL && node->right == NULL) {
                    isFindMin = true;
                    break;
                }
                if (node->left != NULL) {
                    v.push_back(node->left);
                }
                if (node->right != NULL) {
                    v.push_back(node->right);
                }
            }

            // 找到最小深度
            if (isFindMin) {
                break;
            }

            for (vector<TreeNode*>::iterator it = v.begin(); it != v.end(); ++it) {
                q.push(*it);
            }
            v.clear();
        }

        return count;
    }
};