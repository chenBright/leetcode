#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        countNodes(root, maxPath);

        return maxPath;
    }

private:
    int countNodes(TreeNode* root, int& maxPath) {
        if (root == NULL) {
            return 0;
        }
        
        // 如果子树路径和为负，则应当置 0 ，表示最大路径不包含子树。
        int left = max(countNodes(root->left, maxPath), 0);
        int right = max(countNodes(root->right, maxPath), 0);

        // 判断在该节点包含左右子树的路径和，是否大于当前最大路径和。
        maxPath = max(maxPath, root->val + left + right);

        // 返回单边的最大值
        return root->val + max(left, right);
    }
};
