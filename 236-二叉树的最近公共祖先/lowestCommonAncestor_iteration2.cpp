#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> childToParent; // <子结点 , 父结点>
        childToParent[root] = NULL;

        queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        // 层序遍历
        while (childToParent.count(p) == 0 || childToParent.count(q) == 0) {
            TreeNode *node = nodeQ.front();
            nodeQ.pop();

            if (node->left != NULL) {
                childToParent[node->left] = node;
                nodeQ.push(node->left);
            }

            if (node->right != NULL) {
                childToParent[node->right] = node;
                nodeQ.push(node->right);
            }
        }

        unordered_set<TreeNode*> parentSet;
        // 找出 p 的所有父结点
        while (p != NULL) {
            parentSet.insert(p);
            p = childToParent[p];
        }

        // 第一个存在于 parentSet 的 q 的父结点，即为最近公共祖先
        while (parentSet.count(q) == 0) {
            q = childToParent[q];
        }

        return q;
    }
};
