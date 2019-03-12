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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> v; // 保存子结点
        vector<int> temp; // 暂存行结果
        while (!q.empty()) {
            // 一次性处理一行
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
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
            res.push_back(temp); // 保存结果
            temp.clear();
            v.clear();
        }

        return res;
    }
};