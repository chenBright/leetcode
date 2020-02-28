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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;              // 暂存层结果
        TreeNode* lastNode = root;      // 当前层的最后一个结点（最右边的结点）
        TreeNode* nextLastNode = NULL;  // 下一层的最后一个结点（最右边的结点）
        int count = 1;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if (node->left != NULL) {
                nextLastNode = node->left;
                q.push(node->left);
            }
            if (node->right != NULL) {
                nextLastNode = node->right;
                q.push(node->right);
            }

            if (node == lastNode) {
                // 偶数层逆向打印
                if (count % 2 == 0) {
                    reverse(level.begin(), level.end());
                }
                ++count;
                result.push_back(level);
                level.clear();
                lastNode = nextLastNode;
            }
        }

        return result;
    }
};
