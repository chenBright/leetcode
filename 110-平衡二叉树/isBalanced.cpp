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
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalanced(root, &depth);
    }

private:
    bool isBalanced(TreeNode *root, int *treeDepth) {
        if (root == NULL) {
            *treeDepth = 0;
            return true;
        }

        int leftTreeDepth = 0;
        int rightTreeDepth = 0;
        if (isBalanced(root->left, &leftTreeDepth) && isBalanced(root->right, &rightTreeDepth)) {
            int diff = abs(leftTreeDepth - rightTreeDepth);
            if (diff <= 1) {
                *treeDepth = max(leftTreeDepth, rightTreeDepth) + 1;
                return true;
            }
        }

        return false;
    }
};