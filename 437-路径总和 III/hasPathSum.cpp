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
    int pathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return 0;
        }

        return pathSumRecursion(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:

    int pathSumRecursion(TreeNode *root, int sum) {
        if (root == NULL) {
            return 0;
        }

        int count = 0;
        sum -= root->val;
        if (sum == 0) {
            count = 1;
        }

        return count + pathSumRecursion(root->left, sum) + pathSumRecursion(root->right, sum);
    }
};
