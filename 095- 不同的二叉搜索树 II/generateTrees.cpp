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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        } else {
            return generateTrees(1, n);
        }
    }

private:
    // 生成二叉搜索树集合
    vector<TreeNode*> generateTrees(int left, int right) {
        vector<TreeNode*> res;
        if (left > right) {
            res.push_back(NULL); // 空
            return res;
        }

        for (int i = left; i <= right; ++i) {
            vector<TreeNode*> leftTrees = generateTrees(left, i - 1); // 左子树集合
            vector<TreeNode*> rightTrees = generateTrees(i + 1, right); // 右子树集合

            // 以 i 为根结点，组合不同的左子树和右子树，生成不同的二叉搜索树
            for (auto leftTree : leftTrees) {
                for (auto rightTree : rightTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};