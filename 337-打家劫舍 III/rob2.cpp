#include <vector>
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
    int rob(TreeNode* root) {
        vector<int> result = dfs(root);

        return max(result[0], result[1]);
    }
private:
    vector<int> dfs(TreeNode* root) {
        if (root == NULL) {
            return vector<int>(2, 0);
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        // result[0] 表示不偷取当前结点的最大值。
        // result[1] 表示偷取当前结点的最大值。
        vector<int> result(2, 0);
        // 不偷取当前结点
        result[0] = max(left[0], left[1]) + max(right[0], right[1]);
        // 偷取当前结点
        result[1] = left[0] + right[0] + root->val;

        return result;
    }
};
