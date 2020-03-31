#include <climits>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        if (root == NULL) {
            return INT_MIN;
        }

        stack<TreeNode*> s;
        TreeNode *node = root;
        while (!s.empty() || node != NULL) {
            if (node != NULL) {
                s.push(node);
                node = node->left;
            } else {
                --k;
                // 当前结点是第k小的结点
                if (k == 0) {
                    return s.top()->val;
                }
                node = s.top()->right;
                s.pop();
            }
        }

        return INT_MIN;
    }
};