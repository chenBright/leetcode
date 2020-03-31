#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int &k) {
        if (root == NULL) {
            return INT_MIN;
        }

        int left = kthSmallest(root->left, k);
        if (k == 0) { // 在左子树找到第k小的结点
            return left;
        }

        // 当前结点是第k小的结点
        if (--k == 0) {
            return root->val;
        }

         // 在右子树找到第k小的结点
        return kthSmallest(root->right, k);
    }
};