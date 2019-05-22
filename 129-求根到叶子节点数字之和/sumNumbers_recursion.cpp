#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        sumNumbersRecursion(root, 0);
        return sum;
    }

private:
    int sum;
    void sumNumbersRecursion(TreeNode *node, int subSum) {
        if (node == NULL) {
            return;
        }

        int s = subSum * 10 + node->val;
        if (node->left != NULL) {
            sumNumbersRecursion(node->left, s);
        }

        if (node->right != NULL) {
            sumNumbersRecursion(node->right, s);
        }

        if (node->left == NULL && node->right == NULL) {
            sum += s;
        }
        
    }
};